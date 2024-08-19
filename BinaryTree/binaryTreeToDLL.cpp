#include <bits/stdc++.h>
using namespace std;

void findHead(Node *root, Node *&head, Node *&prev)
{

    // Base case.
    if (root == NULL)
    {
        return;
    }

    findHead(root->left, head, prev);

    if (head == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }

    prev = root;

    findHead(root->right, head, prev);
}

// Function to convert binary tree to doubly linked list and return it.

Node *bToDLL(Node *root)
{
    Node *head = NULL;
    Node *prev = NULL;
    findHead(root, head, prev);

    return head;
}