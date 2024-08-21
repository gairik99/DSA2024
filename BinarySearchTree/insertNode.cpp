#include <bits/stdc++.h>
using namespace std;

Node *insert(Node *node, int data)
{
    // Your code goes hereif
    if (node == NULL)
        return new Node(data);
    if (node->data == data)
        return node;
    if (node->data > data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}