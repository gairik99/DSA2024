#include <bits/stdc++.h>
using namespace std;

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    diameter = max(diameter, left + right);
    return max(left, right) + 1;
}

int diameter = 0;

int diameterOfBinaryTree(TreeNode *root)
{
    // your code goes here
    diameter = 0;
    height(root);
    return diameter;
}