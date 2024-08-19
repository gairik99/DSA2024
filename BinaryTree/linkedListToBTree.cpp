#include <bits/stdc++.h>
using namespace std;

void convert(Node *head, TreeNode *&root)
{
    if (head == NULL)
    {
        root == NULL;
        return;
    }
    queue<TreeNode *> q;
    root = new TreeNode(head->data);
    q.push(root);
    head = head->next;
    while (head)
    {
        TreeNode *node = q.front();
        q.pop();
        TreeNode *left = new TreeNode(head->data);
        node->left = left;
        q.push(left);
        head = head->next;
        if (head)
        {
            TreeNode *right = new TreeNode(head->data);
            node->right = right;
            q.push(right);
            head = head->next;
        }
    }
}