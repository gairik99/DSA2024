#include <bits/stdc++.h>
using namespace std;

void dfs(TreeNode *node, vector<int> &path, vector<vector<int>> &allPaths)
{
    if (!node)
    {
        return; // Base case: return if the current node is null
    }
    if (!node->left && !node->right)
    {
        path.push_back(node->data);
        allPaths.push_back(path);
        path.pop_back();
    }
    // Add the current node's data to the path
    path.push_back(node->data);

    if (node->left)
        // Recursively call the function on the left child
        dfs(node->left, path, allPaths);
    // Recursively call the function on the right child
    if (node->right)
        dfs(node->right, path, allPaths);
    // Backtrack by removing the last node from the path
    path.pop_back();
}
vector<vector<int>> allRootToLeaf(TreeNode *root)
{
    // your code goes here
    vector<vector<int>> allPaths; // Vector to store all root-to-leaf paths
    vector<int> currentPath;      // Vector to store the current path

    dfs(root, currentPath, allPaths);

    return allPaths;
}