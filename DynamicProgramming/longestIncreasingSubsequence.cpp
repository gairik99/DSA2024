#include <bits/stdc++.h>
using namespace std;

int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>> &dp)
{
    // Base condition
    if (ind == n)
        return 0;

    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];

    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);

    int take = 0;

    if (prev_index == -1 || arr[ind] > arr[prev_index])
    {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }

    return dp[ind][prev_index + 1] = max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Create a 2D DP array initialized to -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return getAns(arr, n, 0, -1, dp);
}