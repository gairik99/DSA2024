#include <bits/stdc++.h>
using namespace std;

TreeNode *lca(TreeNode *root, int p, int q)
{
    // your code goes here
    if (root == nullptr || root->data == p || root->data == q)
    {
        return root;
    }

    // Recursively find the lowest common ancestor in the left subtree
    TreeNode *left = lca(root->left, p, q);
    // Recursively find the lowest common ancestor in the right subtree
    TreeNode *right = lca(root->right, p, q);

    // If both subtrees contain the nodes, the current root is the lowest common ancestor
    if (left != nullptr && right != nullptr)
    {
        return root;
    }

    // If the left subtree doesn't contain the common ancestor, return the right subtree result
    return left != nullptr ? left : right;
}