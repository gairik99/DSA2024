#include <bits/stdc++.h>
using namespace std;

Node *createTree(vector<int> parent)
{
    // Your code here
    vector<Node *> node;
    for (int i = 0; i < parent.size(); i++)
        node.push_back(new Node(i));
    Node *root = NULL;
    for (int i = 0; i < parent.size(); i++)
    {
        if (parent[i] == -1)
            root = node[i];
        else if (node[parent[i]]->left == NULL)
            node[parent[i]]->left = node[i];
        else
            node[parent[i]]->right = node[i];
    }
    return root;
}