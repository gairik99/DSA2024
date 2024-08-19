#include <bits/stdc++.h>
using namespace std;

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = height(root->left);
    if (left == -1)
        return -1;
    int right = height(root->right);
    if (right == -1)
        return -1;
    if (abs(left - right) > 1)
        return -1;
    return max(left, right) + 1;
}
bool isBalanced(TreeNode *root)
{
    // your code goes here
    return height(root) != -1;
}