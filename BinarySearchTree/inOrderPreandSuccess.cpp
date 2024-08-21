#include <bits/stdc++.h>
using namespace std;

void findPreSuc(TreeNode *root, int key, vector<int> &ans)
{
    // Your code goes here
    if (!root)
        return;
    if (key < root->data)
    {
        ans[1] = root->data;
        findPreSuc(root->left, key, ans);
    }
    else if (key > root->data)
    {
        ans[0] = root->data;
        findPreSuc(root->right, key, ans);
    }
    else
    {
        findPreSuc(root->right, key, ans);
        findPreSuc(root->left, key, ans);
    }
}
vector<int> succPredBST(TreeNode *root, int key)
{
    // your code goes here
    vector<int> ans(2, -1);
    findPreSuc(root, key, ans);
    return ans;
}