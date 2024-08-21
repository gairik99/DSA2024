#include <bits/stdc++.h>
using namespace std;

int countX(Node *root, int &count, int x)
{
    // if tree is empty
    if (!root)
        return 0;

    // sum of nodes in the left subtree
    int ls = countX(root->left, count, x);

    // sum of nodes in the right subtree
    int rs = countX(root->right, count, x);

    // sum of nodes in the subtree rooted
    // with 'root->data'
    int sum = ls + rs + root->data;

    // if true
    if (sum == x)
        count++;

    // return subtree's nodes sum
    return sum;
}

int countSubtreesWithSumX(Node *root, int X)
{
    // Code here
    if (!root)
        return 0;
    int val = 0;
    countX(root, val, X);
    return val;
}