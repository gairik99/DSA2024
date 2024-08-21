#include <bits/stdc++.h>
using namespace std;

int maxDiffUtil(Node *t, int &res)
{
    /* Returning Maximum int value if node is not
       there (one child case)  */
    if (t == NULL)
        return INT_MAX;

    /* Returning minimum value got so far */
    int lf = maxDiffUtil(t->left, res);
    int rf = maxDiffUtil(t->right, res);
    int diff = t->data - min(lf, rf);
    res = max(res, diff);
    return min(lf, min(rf, t->data));
}

int maxDiff(Node *root)
{
    // Your code here
    // Initialising result with minimum int value
    int res = INT_MIN;

    maxDiffUtil(root, res);

    return res;
}