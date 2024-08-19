#include <bits/stdc++.h>
using namespace std;

bool symmetricHelper(TreeNode *left, TreeNode *right)
{
    if (left == nullptr && right == nullptr)
        return true;
    if (left == nullptr || right == nullptr)
        return false;
    if (left->data != right->data)
        return false;
    return symmetricHelper(left->left, right->right) && symmetricHelper(left->right, right->left);
}
bool isSymmetric(TreeNode *root)
{
    // your code goes here
    if (root == nullptr)
        return true;
    return symmetricHelper(root->left, root->right);
}