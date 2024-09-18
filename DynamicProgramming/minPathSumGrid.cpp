#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // Base Conditions
    if (j < 0 || j >= m || i < 0)
        return 1e9;
    if (i == 0)
        return matrix[0][j];

    /* If the result for this cell is
    already calculated, return it*/
    if (dp[i][j] != -1)
        return dp[i][j];

    /* Calculate the minimum path sum by
    considering three possible directions:
    up, left diagonal, and right diagonal*/
    int up = matrix[i][j] + func(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + func(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + func(i - 1, j + 1, m, matrix, dp);

    // Store the minimum of the three paths in dp
    return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // Memoization table to store computed results
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int mini = INT_MAX;

    /* Iterate through each cell in the first row
    to find minimum path sum starting from each of them*/
    for (int j = 0; j < m; j++)
    {
        int ans = func(n - 1, j, m, matrix, dp);
        mini = min(mini, ans);
    }
    // Return the minimum path sum
    return mini;
}