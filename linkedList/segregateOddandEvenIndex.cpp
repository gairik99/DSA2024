#include <bits/stdc++.h>
using namespace std;

ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    /*Initialize pointers for odd
    and even nodes and keep
    track of the first even node*/
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *firstEven = head->next;

    // Rearranging nodes
    while (even && even->next)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    /* Connect the last odd
    node to the first even node*/
    odd->next = firstEven;

    return head;
}