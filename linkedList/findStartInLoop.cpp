#include <bits/stdc++.h>
using namespace std;

ListNode *findStartingPoint(ListNode *head)
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

    if (slow != fast)
        return nullptr;

    slow = head;

    while (slow != fast)
    {

        // Move slow and fast one step
        // At a time
        slow = slow->next;
        fast = fast->next;

        // When slow and fast meet again,
        // It's the first node of the loop
    }

    // Return the first node of the loop
    return slow;
}