#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
    /* Base case: If there are no items left
    or the knapsack has no capacity, return 0 */
    if (ind == 0)
    {
        if (W >= wt[ind])
            return val[ind];
        return 0;
    }
    if (W == 0)
        return 0;

    /* If the result for this state is
    already calculated, return it */
    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }

    /* Calculate the maximum value by either
    excluding the current item or including it */
    int notTaken = func(wt, val, ind - 1, W, dp);
    int taken = 0;

    /* Check if the current item can be included
    without exceeding the knapsack's capacity */
    if (wt[ind] <= W)
    {
        taken = val[ind] + func(wt, val, ind - 1, W - wt[ind], dp);
    }

    // Store the result in the DP table and return
    return dp[ind][W] = max(notTaken, taken);
}
int knapsack01(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return func(wt, val, n - 1, W, dp);
}