#include <bits/stdc++.h>
using namespace std;

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // Dummy nodes to point to heads of
    // three lists
    ListNode *zeroHead = new ListNode(-1);
    ListNode *oneHead = new ListNode(-1);
    ListNode *twoHead = new ListNode(-1);

    // Pointers to current last nodes of
    // three lists
    ListNode *zero = zeroHead;
    ListNode *one = oneHead;
    ListNode *two = twoHead;
    ListNode *temp = head;

    /* Traverse the original list
    and distribute the nodes
    into three lists*/
    while (temp != NULL)
    {
        if (temp->val == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->val == 1)
        {
            one->next = temp;
            one = temp;
        }
        else if (temp->val == 2)
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    // Connect the three lists together
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;

    // New head of the sorted list
    ListNode *newHead = zeroHead->next;

    // Delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}