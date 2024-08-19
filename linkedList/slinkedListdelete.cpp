#include <bits/stdc++.h>
using namespace std;

ListNode *deleteHead(ListNode *&head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    // Set temporary pointer
    ListNode *temp = head;
    // Update head to the next node
    head = head->next;
    // Delete original head
    delete temp;
    // Return new head
    return head;
}

ListNode *deleteTail(ListNode *&head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    /* Initialize a temporary
    pointer to traverse the list*/
    ListNode *temp = head;

    /*Traverse to the second last
     node in the list*/
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // Delete the last node
    delete temp->next;

    /*Set the next of the second
    last node to nullptr,
    effectively removing the last node*/
    temp->next = nullptr;

    // Return head of modified list
    return head;
}

ListNode *deleteKthNode(ListNode *&head, int k)
{
    if (head == NULL)
        return head;

    // If k is 1, delete the first node
    if (k == 1)
    {
        ListNode *temp = head;
        head = head->next;
        delete (temp);
        return head;
    }

    // Traverse the list to find the k-th node
    ListNode *temp = head;
    ListNode *prev = NULL;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        // If the k-th node is found
        if (cnt == k)
        {
            // Adjust the pointers to skip the k-th node
            prev->next = temp->next;
            // Delete the k-th node
            delete temp;
            break;
        }
        // Move to the next node
        prev = temp;
        temp = temp->next;
    }

    return head;
}

ListNode *deleteNodeWithValueX(ListNode *&head, int X)
{
    if (head == NULL)
        return head;

    // If first node has target value, delete
    if (head->val == X)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode *temp = head;
    ListNode *prev = NULL;

    /*Traverse the list to find
    the node with the target value*/
    while (temp != NULL)
    {
        if (temp->val == X)
        {
            // Adjust the pointers
            prev->next = temp->next;
            // Delete node
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}