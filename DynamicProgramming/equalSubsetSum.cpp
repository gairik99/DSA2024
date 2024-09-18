#include <bits/stdc++.h>
using namespace std;

bool func(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    /* Base case: If the target sum is
    0, we found a valid partition*/
    if (target == 0)
        return true;

    /* Base case: If we have considered all elements
    and the target is still not 0, return false*/
    if (ind == 0)
        return arr[0] == target;

    /* If the result for this state
    is already calculated, return it*/
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Exclude the current element
    bool notTaken = func(ind - 1, target, arr, dp);

    /* Include the current element if
    it doesn't exceed the target*/
    bool taken = false;
    if (arr[ind] <= target)
        taken = func(ind - 1, target - arr[ind], arr, dp);

    // Store the result and return it
    return dp[ind][target] = notTaken || taken;
}

int equalPartition(int n, vector<int> arr)
{
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    /* If the total sum is odd, it cannot
    be partitioned into two equal subsets*/
    if (totSum % 2 == 1)
        return false;

    else
    {
        int k = totSum / 2;

        /* Initialize a DP table with dimensions
        n x k+1 and initialize with -1*/
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        // Return the result
        return func(n - 1, k, arr, dp);
    }
}