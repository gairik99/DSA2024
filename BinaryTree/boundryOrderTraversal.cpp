#include <bits/stdc++.h>
using namespace std;

bool isLeaf(TreeNode *root)
{
    return !root->left && !root->right;
}

// Function to add the left boundary of the tree
void addLeftBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

// Function to add the right boundary of the tree
void addRightBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; --i)
    {
        res.push_back(temp[i]);
    }
}

// Function to add the leaves of the tree
void addLeaves(TreeNode *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
    {
        addLeaves(root->left, res);
    }
    if (root->right)
    {
        addLeaves(root->right, res);
    }
}

vector<int> boundary(TreeNode *root)
{
    // your code goes here
    vector<int> res;
    if (!root)
    {
        return res;
    }
    if (!isLeaf(root))
    {
        res.push_back(root->data);
    }

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}