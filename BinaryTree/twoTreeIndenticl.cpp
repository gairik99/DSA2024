#include <bits/stdc++.h>
using namespace std;

bool isSameTree(TreeNode *p, TreeNode *q)
{
    // your code goes here
    if (p == nullptr && q == nullptr)
        return true;
    if (p != nullptr && q == nullptr)
        return false;
    if (p == nullptr && q != nullptr)
        return false;
    if (p->data != q->data)
        return false;
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);

    return left && right;
}