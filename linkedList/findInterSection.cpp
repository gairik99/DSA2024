#include <bits/stdc++.h>
using namespace std;

ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
{
    ListNode *t1 = head1; // t1 is unclear, suggest renaming to 'current1'
    ListNode *t2 = head2; // t2 is unclear, suggest renaming to 'current2'

    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;

        if (t1 == t2)
        {
            break;
        }

        if (t1 == NULL)
            t1 = head2;
        if (t2 == NULL)
            t2 = head1;
    }

    if (t1 != NULL)
        return t1;
    else
    {
        return -1;
    }
}