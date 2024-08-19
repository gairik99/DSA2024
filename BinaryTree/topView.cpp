#include <bits/stdc++.h>
using namespace std;

vector<int> topView(TreeNode *root)
{
    // your code goes here
    if (root == NULL)
        return {};
    map<int, int> mpp;
    queue<pair<TreeNode *, int>> m;
    vector<int> ans;
    m.push({root, 0});
    while (!m.empty())
    {
        auto it = m.front();
        m.pop();
        root = it.first;
        int ind = it.second;
        if (mpp.find(ind) == mpp.end())
            mpp[ind] = root->data;
        if (root->left)
            m.push({root->left, ind - 1});
        if (root->right)
            m.push({root->right, ind + 1});
    }
    for (auto it : mpp)
        ans.push_back(it.second);
    return ans;
}