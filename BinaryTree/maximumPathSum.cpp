#include <bits/stdc++.h>
using namespace std;

int findMaxUtil(TreeNode *root, int &res)
{
    // Base Case
    if (root == NULL)
        return 0;

    // l and r store maximum path sum going through left and
    // right child of root respectively
    int l = findMaxUtil(root->left, res);
    int r = findMaxUtil(root->right, res);

    // Max path for parent call of root. This path must
    // include at-most one child of root
    int max_single = max(max(l, r) + root->data, root->data);

    // Max Top represents the sum when the Node under
    // consideration is the root of the maxsum path and no
    // ancestors of root are there in max sum path
    int max_top = max(max_single, l + r + root->data);

    res = max(res, max_top); // Store the Maximum Result.

    return max_single;
}

int maxPathSum(TreeNode *root)
{
    // your code goes here
    int maxi = INT_MIN;

    // Call the recursive function to
    // find the maximum path sum
    findMaxUtil(root, maxi);

    // Return the final maximum path sum
    return maxi;
}