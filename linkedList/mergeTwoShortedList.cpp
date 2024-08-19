#include <bits/stdc++.h>
using namespace std;

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr)
    {
        /*Compare elements of both lists
        and link the smaller node
        to the merged list*/
        if (list1->val <= list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next;
    }

    /*If any list still
    has remaining elements,
    append them to the merged list*/
    if (list1)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }

    // Return merged list
    return dummyNode->next;
}