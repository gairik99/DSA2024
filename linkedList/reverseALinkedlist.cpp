#include <bits/stdc++.h>
using namespace std;

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *newHead = reverseList(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head, *next = head, *prev = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}