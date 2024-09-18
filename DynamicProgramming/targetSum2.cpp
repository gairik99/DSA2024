#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;
int func(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case
    if (ind == 0)
    {
        // Include or exclude the element
        if (target == 0 && arr[0] == 0)
            return 2;
        // One way to partition
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }

    /* If the result for this index and target
    sum is already calculated, return it*/
    if (dp[ind][target] != -1)
        return dp[ind][target];

    /* Calculate the number of ways
    without taking the current element*/
    int notTaken = func(ind - 1, target, arr, dp) % mod;

    /* Calculate the number of ways
    by taking the current element*/
    int taken = 0;
    if (arr[ind] <= target)
        taken = func(ind - 1, target - arr[ind], arr, dp) % mod;

    /* Store the sum of ways in
    the DP array and return it*/
    return dp[ind][target] = (notTaken + taken) % mod;
}

int targetSum(int n, int target, vector<int> &nums)
{
    int totSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        totSum += nums[i];
    }

    // Not possible to achieve the target sum
    if (totSum - target < 0)
        return 0;
    /* The difference between the total
    sum and target sum must be even*/
    if ((totSum - target) % 2 == 1)
        return 0;

    // Calculate the required sum for each subset
    int s2 = (totSum - target) / 2;

    // Initialize DP table
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));

    // Return the result
    return func(n - 1, s2, nums, dp);
}