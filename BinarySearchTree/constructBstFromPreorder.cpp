#include <bits/stdc++.h>
using namespace std;

TreeNode *bstFromPreorderHelper(vector<int> &preorder, int bound, int &index)
{
    // If all elements are used or the next element
    // is greater than the bound, return null
    if (index == preorder.size() || preorder[index] > bound)
        return nullptr;

    // Create a new TreeNode with the current value
    TreeNode *root = new TreeNode(preorder[index++]);

    // Recursively construct the left subtree
    // with the current value as the new bound
    root->left = bstFromPreorderHelper(preorder, root->data, index);

    // Recursively construct the right subtree
    // with the same bound as the parent's bound
    root->right = bstFromPreorderHelper(preorder, bound, index);

    // Return the constructed subtree's root
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    // your code goes here
    int index = 0; // Initialize index
    return bstFromPreorderHelper(preorder, INT_MAX, index);
}