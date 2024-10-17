#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int ans = func(arr, i, k, dp) + func(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        mini = min(mini, ans);
    }
    // Store and return the minimum cost found
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &nums)
{
    int N = nums.size();
    int i = 1;
    int j = N - 1;

    vector<vector<int>> dp(N, vector<int>(N, -1));
    return func(nums, i, j, dp);
}