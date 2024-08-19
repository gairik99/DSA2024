#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> levelOrder(TreeNode *root)
{
    // your code goes here
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        // If the tree is empty, return an empty vector
        return ans;
    }

    // Create a queue to store nodes for level-order traversal
    queue<TreeNode *> q;
    // Push the root node to the queue
    q.push(root);

    while (!q.empty())
    {
        // Get the size of the current level
        int size = q.size();
        // Create a vector to store nodes at the current level
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            // Get the front node in the queue
            TreeNode *node = q.front();
            // Remove the front node from the queue
            q.pop();
            // Store the node value in the current level vector
            level.push_back(node->data);

            // Enqueue the child nodes if they exist
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        // Store the current level in the answer vector
        ans.push_back(level);
    }
    // Return the level-order traversal of the tree
    return ans;
}