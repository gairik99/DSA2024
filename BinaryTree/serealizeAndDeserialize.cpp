#include <bits/stdc++.h>
using namespace std;

void preOrder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        ans.push_back(-1);
        return;
    }

    ans.push_back(root->data);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}
vector<int> serialize(Node *root)
{
    // Your code here
    vector<int> ans;
    preOrder(root, ans);
    return ans;
}

// Function to deserialize a list and construct the tree.
int index = 0;
Node *deSerialize(vector<int> &a)
{
    // Your code here
    if (index == a.size())
        return NULL;

    int val = a[index++];
    if (val == -1)
        return NULL;

    Node *root = new Node(val);
    root->left = deSerialize(a);
    root->right = deSerialize(a);
    return root;
}