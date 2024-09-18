#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == n - 1)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + func(i + 1, j, n, triangle, dp);
    int diagonal = triangle[i][j] + func(i + 1, j + 1, n, triangle, dp);

    // Store the sum in dp and return it
    return dp[i][j] = min(down, diagonal);
}
int minTriangleSum(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    /* Initialize a memoization table
    to store computed results*/
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // Return the minimum path sum
    //  return func(0, 0,n,triangle,dp);
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}