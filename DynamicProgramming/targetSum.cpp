#include <bits/stdc++.h>
using namespace std;

bool func(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[ind] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int notPick = func(ind - 1, target, arr, dp);
    int pick = false;
    if (arr[ind] <= target)
        pick = func(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notPick || pick;
}

bool isSubsetSum(vector<int> arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    // Fill the DP array iteratively
    for (int ind = 1; ind < n; ind++)
    {
        for (int i = 1; i <= target; i++)
        {

            /* If we don't take the current element, the
            result is the same as the previous row*/
            bool notTaken = dp[ind - 1][i];

            /* If we take the current element, subtract its
            value from the target and check the previous row*/
            bool taken = false;
            if (arr[ind] <= i)
            {
                taken = dp[ind - 1][i - arr[ind]];
            }
            dp[ind][i] = notTaken || taken;
        }
    }

    // The final result is stored in dp[n-1][k]
    return dp[n - 1][target];
}