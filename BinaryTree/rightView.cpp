#include <bits/stdc++.h>
using namespace std;

vector<int> rightSideView(TreeNode *root)
{
    // your code goes here
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (i == 0)
            {
                ans.push_back(node->data);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }

            if (node->left != NULL)
            {
                q.push(node->left);
            }
        }
    }
    return ans;
}