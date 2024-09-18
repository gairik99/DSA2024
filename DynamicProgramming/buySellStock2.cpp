#include <bits/stdc++.h>
using namespace std;

int func(int ind, int buy, int n, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case
    if (ind == n)
    {
        return 0;
    }
    /* If the result for this state has
    already been calculated, return it*/
    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }
    int profit = 0;

    // We can buy the stock
    if (buy == 0)
    {
        profit = max(0 + func(ind + 1, 0, n, arr, dp), -arr[ind] + func(ind + 1, 1, n, arr, dp));
    }

    // We can sell the stock
    if (buy == 1)
    {
        profit = max(0 + func(ind + 1, 1, n, arr, dp), arr[ind] + func(ind + 1, 0, n, arr, dp));
    }

    /* Store the value in dp array and
    return the calculated profit */
    return dp[ind][buy] = profit;
}

int stockBuySell(vector<int> arr, int n)
{
    if (n == 0)
        return 0;
    // Initialize a DP table to memoize results
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    // int ans = func(0, 0, n, arr, dp);

    // //Return the maximum profit
    // return ans;

    dp[n][0] = dp[n][1] = 0;

    int profit;

    // Loop through the array in reverse order
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            // We can buy the stock
            if (buy == 0)
            {
                profit = max(0 + dp[ind + 1][0], (-1) * arr[ind] + dp[ind + 1][1]);
            }

            // We can sell the stock
            if (buy == 1)
            {
                profit = max(0 + dp[ind + 1][1], arr[ind] + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    /* The maximum profit is stored in
    dp[0][0] after all calculations*/
    return dp[0][0];
}