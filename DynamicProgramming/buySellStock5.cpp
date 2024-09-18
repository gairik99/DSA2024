#include <bits/stdc++.h>
using namespace std;

int func(int ind, int buy, int fee, int n, vector<int> &prices, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    int profit = 0;
    if (buy == 0)
    {
        profit = max(func(ind + 1, 0, fee, n, prices, dp), -prices[ind] + func(ind + 1, 1, fee, n, prices, dp));
    }
    else
    {
        profit = max(func(ind + 1, 1, fee, n, prices, dp), -fee + prices[ind] + func(ind + 1, 0, fee, n, prices, dp));
    }
    return dp[ind][buy] = profit;
}

int stockBuySell(vector<int> prices, int n, int fee)
{
    if (n == 0)
        return 0;
    // Initialize a DP table to memoize results
    vector<vector<int>> dp(n, vector<int>(2, -1));
    int ans = func(0, 0, fee, n, prices, dp);

    // Return the maximum profit
    return ans;
}