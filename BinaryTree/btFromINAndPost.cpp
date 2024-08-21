#include <bits/stdc++.h>
using namespace std;

int indx;
unordered_map<int, int> mp;
Node *rec(int post[], int lo, int hi)
{
    if (lo > hi)
        return NULL;
    Node *node = new Node(post[indx--]);
    if (lo == hi)
        return node;
    int mid = mp[node->data];
    node->right = rec(post, mid + 1, hi);
    node->left = rec(post, lo, mid - 1);

    return node;
}

Node *buildTree(int n, int in[], int post[])
{
    // Your code here
    indx = n - 1;
    mp.clear();
    for (int i = 0; i < n; i++)
        mp[in[i]] = i;
    Node *root = rec(post, 0, n - 1);
    return root;
}