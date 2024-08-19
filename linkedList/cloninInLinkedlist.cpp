#include <bits/stdc++.h>
using namespace std;

void insertCopyInBetween(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        ListNode *nextElement = temp->next;
        // Create a new node with the same data
        ListNode *copy = new ListNode(temp->val);

        copy->next = nextElement;

        temp->next = copy;

        temp = nextElement;
    }
}

// Function to connect random pointers of the copied nodes
void connectRandomPointers(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        // Access the copied node
        ListNode *copyNode = temp->next;

        /*If the original node has a random pointer
        point the copied node's random to the
        corresponding copied random node
        set the copied node's random to null
        if the original random is null*/
        if (temp->random)
        {

            copyNode->random = temp->random->next;
        }
        else
        {

            copyNode->random = NULL;
        }

        // Move to next original node
        temp = temp->next->next;
    }
}

// Function to retrieve the deep copy of the linked list
ListNode *getDeepCopyList(ListNode *head)
{
    ListNode *temp = head;
    // Create a dummy node
    ListNode *dummyNode = new ListNode(-1);
    // Initialize a result pointer
    ListNode *res = dummyNode;

    while (temp != NULL)
    {
        /*Creating a new List by
        pointing to copied nodes*/
        res->next = temp->next;
        res = res->next;

        /*Disconnect and revert back
        to the initial state of the
        original linked list*/
        temp->next = temp->next->next;
        temp = temp->next;
    }

    /*Return the deep copy
    of the list starting
    from the dummy node*/
    return dummyNode->next;
}

ListNode *copyRandomList(ListNode *head)
{
    if (!head)
        return nullptr;

    // Insert nodes in between
    insertCopyInBetween(head);
    // Connect random pointers
    connectRandomPointers(head);
    // Retrieve deep copy of inked list
    return getDeepCopyList(head);
}