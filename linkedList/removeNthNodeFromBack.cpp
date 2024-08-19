#include <bits/stdc++.h>
using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fastPointer = head; // Line 10: Suggest renaming for clarity
    ListNode *slowPointer = head; // Line 11: Suggest renaming for clarity

    /*Move the fastPointer ahead N nodes*/ // Line 13: Update comment for clarity
    for (int i = 0; i < n; i++)
    {
        fastPointer = fastPointer->next;
    }

    /*If fastPointer becomes NULL the Nth node from the end is the head*/ // Line 17: Update comment for clarity
    if (fastPointer == NULL)
    {
        return head->next;
    }

    /*Move both pointers until fastPointer reaches the end*/ // Line 21: Update comment for clarity
    while (fastPointer->next != NULL)
    {
        fastPointer = fastPointer->next;
        slowPointer = slowPointer->next;
    }

    // Delete the Nth node from the end
    ListNode *delNode = slowPointer->next;
    slowPointer->next = slowPointer->next->next;
    delete delNode;
    return head;
}