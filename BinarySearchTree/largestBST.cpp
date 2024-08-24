#include <bits/stdc++.h>
using namespace std;

class NodeValue
{
public:
    int maxSize, minValue, maxValue;
    NodeValue(int maxS, int minvalue, int maxVal)
    {
        this->maxSize = maxS;
        this->minValue = minvalue;
        this->maxValue = maxVal;
    }
};

class Solution
{
public:
    NodeValue post(TreeNode *root)
    {
        if (root == NULL)
        {
            return NodeValue(0, INT_MAX, INT_MIN);
        }

        auto left = post(root->left);
        auto right = post(root->right);

        if (left.maxValue < root->data && right.minValue > root->data)
        {
            int s = left.maxSize + right.maxSize + 1;
            return NodeValue(s, min(root->data, left.minValue), max(root->data, right.maxValue));
        }
        else
        {
            int s = max(left.maxSize, right.maxSize);
            return NodeValue(s, INT_MIN, INT_MAX);
        }
    }

    int largestBST(TreeNode *root)
    {
        // your code goes here
        return post(root).maxSize;
    }
};