#include <bits/stdc++.h>
using namespace std;

bool validate(TreeNode *node, int min, int max)
{
    // Base case: if the node is null, return true
    if (node == nullptr)
        return true;

    // Check if the node's value falls within the valid range
    if (node->data <= min || node->data >= max)
        return false;

    // Recursively validate the left subtree
    // Update the max value to the current node's value
    bool leftIsValid = validate(node->left, min, node->data);

    // Recursively validate the right subtree
    // Update the min value to the current node's value
    bool rightIsValid = validate(node->right, node->data, max);

    // Both subtrees must be valid for the tree to be a BST
    return leftIsValid && rightIsValid;
}
bool isBST(TreeNode *root)
{
    // your code goes here
    return validate(root, INT_MIN, INT_MAX);
}