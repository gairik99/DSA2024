#include <bits/stdc++.h>
using namespace std;

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    // Step 2: Traverse the linked list with
    // the slow and fast pointers
    while (fast != nullptr && fast->next != nullptr)
    {
        // Move slow one step
        slow = slow->next;
        // Move fast two steps
        fast = fast->next->next;

        // Check if slow and fast pointers meet
        if (slow == fast)
        {
            return true; // Loop detected
        }
    }

    // If fast reaches the end of the list,
    // there is no loop
    return false;
}
