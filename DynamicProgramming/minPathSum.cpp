#include <bits/stdc++.h>
using namespace std;

int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
    if (i < 0 || j < 0)
        return 1e9; // If we go out of bounds, return a large value to avoid considering this path
    if (dp[i][j] != -1)
        return dp[i][j]; // If the result is already computed, return it

    // Calculate the minimum sum path by considering moving up and moving left
    int up = grid[i][j] + helper(i - 1, j, grid, dp);
    int left = grid[i][j] + helper(i, j - 1, grid, dp);

    // Store the result in the DP table and return it
    return dp[i][j] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // return helper(m - 1, n - 1, grid, dp);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = INT_MAX;
            int left = INT_MAX;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = min(left, up) + grid[i][j];
        }
    }
    return dp[m - 1][n - 1];
}