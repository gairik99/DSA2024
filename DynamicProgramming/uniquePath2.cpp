#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // Base case
    if (matrix[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];
    int left = 0, up = 0;
    if (i > 0)
        up = func(i - 1, j, matrix, dp);
    if (j > 0)
        left = func(i, j - 1, matrix, dp);

    // Return the total ways
    return dp[i][j] = up + left;
}

int uniquePathsWithObstacles(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int mod = 1e9 + 7;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {

    //         // Base conditions
    //         if (matrix[i][j] == 1 ) {
    //             /* If there's an obstacle at the
    //             cell, no paths can pass through it*/
    //             dp[i][j] = 0;
    //             continue;
    //         }
    //         if (i == 0 && j == 0) {
    //             /* If we are at the starting
    //             point, there is one path to it*/
    //             dp[i][j] = 1;
    //             continue;
    //         }

    //         int up = 0;
    //         int left = 0;

    //         /* Check if we can move up and left
    //         (if not at the edge of the maze)*/
    //         if (i > 0)
    //             up = dp[i - 1][j]%mod;
    //         if (j > 0)
    //             left = dp[i][j - 1]%mod;

    //         /* Total number of paths to reach (i, j)
    //         is the sum of paths from above and left*/
    //         dp[i][j] = (up + left)%mod;
    //     }
    // }
    // return dp[m - 1][n - 1];

    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j])
            {
                // temp[j]=0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = temp[j - 1];
            temp[j] = (up + left) % mod;
        }
        prev = temp;
    }
    return prev[n - 1];
}