#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
    // Base case: if we're at the first item
    if (ind == 0)
    {
        return (W / wt[0]) * val[0];
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTaken = 0 + func(wt, val, ind - 1, W, dp);

    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + func(wt, val, ind, W - wt[ind], dp);

    return dp[ind][W] = max(notTaken, taken);
}

int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return func(wt, val, n - 1, W, dp);
}