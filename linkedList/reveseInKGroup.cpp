#include <bits/stdc++.h>
using namespace std;

Node *reverseIt(struct node *head, int k)
{
    // Complete this method
    if (head == NULL)
    {
        return NULL;
    }

    // step1: reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step2: Recursion dekhlega aage ka
    if (curr != NULL)
    {
        head->next = reverseIt(curr, k);
    }

    // step3: return head of reversed list
    return prev;
}