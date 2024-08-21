#include <bits/stdc++.h>
using namespace std;

void inorder(TreeNode *root, int &k, int &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    inorder(root->right, k, ans);
}

void reverseIn(TreeNode *root, int &k, int &ans)
{
    if (root == NULL)
        return;
    reverseIn(root->right, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    reverseIn(root->left, k, ans);
}

vector<int> kLargesSmall(TreeNode *root, int k)
{
    // your code goes here
    vector<int> a;
    int ans = -1, n = k;

    inorder(root, n, ans);
    a.push_back(ans);
    ans = -1, n = k;
    reverseIn(root, n, ans);
    a.push_back(ans);
    return a;
}