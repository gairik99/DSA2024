#include <bits/stdc++.h>
using namespace std;

ListNode *insertAtHead(ListNode *&head, int X)
{
    ListNode *temp = new ListNode(X); // Line 10: Suggest adding a comment explaining the purpose of creating a new ListNode
    temp->next = head;
    head = temp;
    return head;
}

ListNode *insertAtTail(ListNode *&head, int X)
{
    if (head == NULL)
        return new ListNode(X);

    ListNode *temp = head;
    // Traversing until the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    ListNode *newNode = new ListNode(X);
    temp->next = newNode;

    return head;
}

ListNode *insertAtKthPosition(ListNode *&head, int x, int k)
{
    if (head == NULL)
    {
        if (k == 1)
            return new ListNode(x);
        else
            return head;
    }

    /*If k is 1, insert the new
     node at the beginning
     of the linked list*/
    if (k == 1)
        return new ListNode(x, head);

    int cnt = 0;
    ListNode *temp = head;

    /* Traverse the linked list
    to find the node at position k-1*/
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k - 1)
        {
            /* Insert the new node after the node
            at position k-1*/
            ListNode *newNode = new ListNode(x);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

ListNode *insertBeforeX(ListNode *&head, int val, int el)
{
    if (head == NULL)
    {
        return NULL;
    }

    // Insert at the beginning if the value matches the head's data
    if (head->val == val)
        return new ListNode(el, head);

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        // Insert at the current position if the next node has the desired value
        if (temp->next->val == val)
        {
            ListNode *newNode = new ListNode(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}