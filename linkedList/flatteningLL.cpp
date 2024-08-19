#include <bits/stdc++.h>
using namespace std;

ListNode *merge(ListNode *list1, ListNode *list2)
{
    // Create a dummy node as a
    // placeholder for the result
    ListNode *dummyNode = new ListNode(-1);
    ListNode *res = dummyNode;

    // Merge the lists based on data values
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            res->child = list1;
            res = res->child;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            res = res->child;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    // Connect the remaining
    // elements if any
    if (list1)
    {
        res->child = list1;
    }
    else
    {
        res->child = list2;
    }

    // Break the last node's
    // link to prevent cycles
    // if(dummyNode->child){
    //     dummyNode->child->next = NULL;
    // }

    return dummyNode->child;
}
ListNode *flattenLinkedList(ListNode *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Recursively flatten the
    // rest of the linked list
    ListNode *mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);
    return head;
}