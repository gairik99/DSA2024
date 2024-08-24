#include <bits/stdc++.h>
using namespace std;

bool twoSumBSTHelper(TreeNode *root, int k, unordered_map<int, int> &mp)
{
    if (root == NULL)
        return false;
    if (twoSumBSTHelper(root->left, k, mp))
        return true;
    if (mp.find(k - root->data) != mp.end())
        return true;
    mp[root->data]++;
    return twoSumBSTHelper(root->right, k, mp);
}

bool twoSumBST(TreeNode *root, int k)
{
    // your code goes here
    unordered_map<int, int> mpp;
    return twoSumBSTHelper(root, k, mpp);
}