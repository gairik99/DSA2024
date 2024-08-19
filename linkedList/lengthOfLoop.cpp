#include <bits/stdc++.h>
using namespace std;

int findLengthOfLoop(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL)
    {

        // Move slow one step
        slow = slow->next;

        // Move fast two steps
        fast = fast->next->next;

        // If slow and fast meet,
        // a loop is detected
        if (slow == fast)
        {

            // Reset the slow pointer
            // To the head of the list
            // Phase 2: Find the first node of the loop
            break;
        }
    }
    if (fast == nullptr || fast->next == nullptr)
        return 0;
    int cnt = 1;
    slow = slow->next;
    while (slow != fast)
    {
        cnt++;
        slow = slow->next;
    }
    return cnt;
}