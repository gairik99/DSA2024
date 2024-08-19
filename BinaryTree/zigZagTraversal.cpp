#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    // your code goes here
    queue<TreeNode *> st;
    st.push(root);
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    int toRight = true;
    while (!st.empty())
    {
        int l = st.size();
        vector<int> vec(l);
        for (int i = 0; i < l; i++)
        {
            root = st.front();
            st.pop();
            if (toRight)
                vec[i] = root->data;
            else
                vec[l - i - 1] = root->data;
            if (root->left)
                st.push(root->left);
            if (root->right)
                st.push(root->right);
        }
        toRight = !toRight;
        ans.push_back(vec);
    }
    return ans;
}