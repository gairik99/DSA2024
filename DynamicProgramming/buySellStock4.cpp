#include <bits/stdc++.h>
using namespace std;

int func(int ind, int buy, int cap, int n, vector<int> &prices,
         vector<vector<vector<int>>> &dp)
{
    if (cap == 0 || ind == n)
        return 0;
    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
    int profit = 0;
    if (buy == 0)
    {
        profit = max(func(ind + 1, 0, cap, n, prices, dp), -prices[ind] + func(ind + 1, 1, cap, n, prices, dp));
    }
    else
    {
        profit = max(func(ind + 1, 1, cap, n, prices, dp), prices[ind] + func(ind + 1, 0, cap - 1, n, prices, dp));
    }
    return dp[ind][buy][cap] = profit;
}

int stockBuySell(vector<int> prices, int n, int k)
{
    if (n == 0)
        return 0;

    // Initialize a DP table to memoize results
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    int ans = func(0, 0, k, n, prices, dp);

    // Return the maximum profit
    return ans;
}