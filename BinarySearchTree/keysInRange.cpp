#include <bits/stdc++.h>
using namespace std;

void printNearNodesUtil(Node *root, int k1, int k2, vector<int> &res)
{
    // base case
    if (root == NULL)
        return;

    // if starting range is less than data at current node, we call
    // the function recursively for the left subtree.
    if (k1 < root->data)
        printNearNodesUtil(root->left, k1, k2, res);

    // if data at current node is within the range given, we store
    // the data at current node in the output list.
    if (k1 <= root->data && root->data <= k2)
        res.push_back(root->data);

    // if ending range is more than data at current node, we call
    // the function recursively for the right subtree.
    if (k2 > root->data)
        printNearNodesUtil(root->right, k1, k2, res);
}

vector<int> printNearNodes(Node *root, int low, int high)
{
    // code here
    vector<int> res;
    printNearNodesUtil(root, low, high, res);
    // returning the output list.
    return res;
}