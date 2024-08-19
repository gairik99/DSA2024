#include <bits/stdc++.h>
using namespace std;

ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    // Initialize slow and fast pointers
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = head;
    // fast = head->next->next;

    // Move 'fast' pointer twice as fast as 'slow'
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node by skipping it
    prev->next = prev->next->next;
    return head;
}
