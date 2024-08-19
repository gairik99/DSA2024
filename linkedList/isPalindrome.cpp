#include <bits/stdc++.h>
using namespace std;

ListNode *reverseLinkedList(ListNode *head)
{
    /* Check if the list is empty
     or has only one node*/
    if (head == NULL || head->next == NULL)
    {
        /*No change is needed;
        return the current head*/
        return head;
    }

    /*Reverse the remaining
    part of the list and get the new head*/
    ListNode *newHead = reverseLinkedList(head->next);

    /*Store the next node in 'front'
    to reverse the link*/
    ListNode *front = head->next;

    /*Update the 'next' pointer of 'front' to
    point to the current head, effectively
    reversing the link direction*/
    front->next = head;

    /* Set the 'next' pointer of the
     current head to 'null' to
     break the original link*/
    head->next = NULL;

    /*Return the new head obtained
    from the recursion*/
    return newHead;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        // It's a palindrome by definition
        return true;
    }

    /* Initialize two pointers, slow and fast,
     to find the middle of the linked list*/
    ListNode *slow = head;
    ListNode *fast = head;

    /* Traverse the linked list to find the
     middle using slow and fast pointers*/
    while (fast->next != NULL && fast->next->next != NULL)
    {
        // Move slow pointer one step
        slow = slow->next;

        // Move fast pointer two steps
        fast = fast->next->next;
    }

    /*Reverse the second half of the
    linked list starting from the middle*/
    ListNode *newHead = reverseLinkedList(slow->next);

    // Pointer to the first half
    ListNode *first = head;

    // Pointer to the reversed second half
    ListNode *second = newHead;
    while (second != NULL)
    {
        /*Compare data values of
        nodes from both halves.
        If values do not match,
        the list is not a palindrome*/
        if (first->val != second->val)
        {
            /*Reverse the second half
            back to its original state*/
            reverseLinkedList(newHead);

            // Not a palindrome
            return false;
        }

        // Move the first pointer
        first = first->next;

        // Move the second pointer
        second = second->next;
    }

    /*Reverse the second half
    back to its original state*/
    reverseLinkedList(newHead);

    // Linked List is a palindrome
    return true;
}