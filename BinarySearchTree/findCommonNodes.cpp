#include <bits/stdc++.h>
using namespace std;

map<int, bool> mp;
void solve1(Node *root1)
{
    if (!root1)
        return;

    solve1(root1->left);
    mp[root1->data] = 1;
    solve1(root1->right);
}

void solve2(Node *root2, vector<int> &ans)
{
    if (!root2)
        return;

    solve2(root2->left, ans);
    if (mp[root2->data])
        ans.push_back(root2->data);
    solve2(root2->right, ans);
}

vector<int> findCommon(Node *root1, Node *root2)
{
    // Your code here
    vector<int> ans;
    solve1(root1);
    solve2(root2, ans);
    return ans;
}