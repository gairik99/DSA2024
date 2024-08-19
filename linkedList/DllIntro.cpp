#include <bits/stdc++.h>
using namespace std;

ListNode *arrayToLinkedList(vector<int> &arr)
{
    // If array is empty, return nullptr
    if (arr.empty())
        return nullptr;

    // Create head node with first element of the array
    ListNode *head = new ListNode(arr[0]);
    // Initialize 'prev' to the head node
    ListNode *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        // Create a new node
        ListNode *temp = new ListNode(arr[i], nullptr, prev);
        // Update 'next' pointer
        prev->next = temp;
        // Move 'prev' to newly created node
        prev = temp;
    }
    // Return head
    return head;
}

ListNode *deleteHead(ListNode *head)
{
    // Line 9: Suggest adding a comment explaining the purpose of this function
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    ListNode *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}

ListNode *deleteTail(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    ListNode *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    ListNode *prev = temp->prev;
    temp->prev = nullptr;
    prev->next = nullptr;
    delete temp;
    return head;
}

ListNode *deleteKthElement(ListNode *head, int k)
{
    if (head == nullptr)
        return head;
    if (k == 1)
    {
        ListNode *temp = head;
        head = head->next;
        // temp->next=nullptr; // Line 22: Commenting out code should be removed if not needed or explained if it serves a purpose
        if (head)
            head->prev = nullptr;
        delete temp;
        return head;
    }
    ListNode *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            ListNode *prev = temp->prev;
            prev->next = temp->next;
            if (temp->next)
                temp->next->prev = prev;
            delete temp;

            return head;
        }
        temp = temp->next;
    }
    return head;
}

void deleteGivenNode(ListNode *temp)
{
    ListNode *prev = temp->prev;
    ListNode *front = temp->next;

    // Edge case if temp is the tail node
    if (front == nullptr)
    {
        prev->next = nullptr;
        // temp-> = nullptr;  // Commented line seems incomplete/inactive
        delete temp;
        return;
    }

    // Disconnect temp
    prev->next = front;
    front->prev = prev;

    // Set temp's pointers to NULL
    temp->next = nullptr;
    // temp->back = nullptr;  // Commented line has incorrect member name (should be prev)

    // Free memory
    delete temp;
}

ListNode *insertBeforeHead(ListNode *head, int X)
{
    ListNode *newHead = new ListNode(X, head, nullptr);
    head->prev = newHead;

    return newHead;
}

ListNode *insertBeforeTail(ListNode *head, int val)
{
    // Edge case
    if (head->next == nullptr)
    {
        // Create new node with data as val
        ListNode *newHead = new ListNode(val, head, nullptr);
        head->prev = newHead;
        return newHead;
    }

    // Create pointer tail
    ListNode *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    // Keep track of node before tail using prev
    ListNode *prev = tail->prev;

    // Create new node with value val
    ListNode *newNode = new ListNode(val, tail, prev);

    // Join the new node
    prev->next = newNode;
    tail->prev = newNode;

    // Return updated linked list
    return head;
}

ListNode *insertBeforeKthPosition(ListNode *head, int val, int k)
{
    if (k == 1)
    {
        // K = 1 means node has to be inserted before the head
        ListNode *newHead = new ListNode(val, head, nullptr);
        head->prev = newHead;
        return newHead;
    }

    // temp will keep track
    ListNode *temp = head;

    // Reach kth element
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        // Break out of the loop
        if (count == k)
            break;
        // Keep moving temp forward
        temp = temp->next;
    }
    // Track the node
    ListNode *prev = temp->prev;

    // Create new node with data as val
    ListNode *newNode = new ListNode(val, temp, prev);

    // Join new node
    prev->next = newNode;
    temp->prev = newNode;

    // Return head
    return head;
}

void insertBeforeGivenNode(ListNode *node, int val)
{
    ListNode *prev = node->prev;

    // Create new node
    ListNode *newNode = new ListNode(val, node, prev);

    // Connect newNode
    prev->next = newNode;
    node->prev = newNode;

    // void function to just update
    return;
}