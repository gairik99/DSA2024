#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<vector<int>> &dp)
{
    // Base case
    if (i == 0 && j == 0)
        return 1;

    /* If we go out of bounds or reach
    a blocked cell, there are no ways.*/

    /* Calculate the number of ways by
    moving up and left recursively.*/
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = 0, left = 0;
    if (i >= 1)
        up = func(i - 1, j, dp);
    if (j >= 1)
        left = func(i, j - 1, dp);

    // Return the total ways
    return dp[i][j] = up + left;
}
int uniquePaths(int m, int n)
{

    vector<vector<int>> dp(m, vector<int>(n, -1));
    //    return func(m-1,n-1,dp);
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //         if (i == 0 && j == 0) {
    //             dp[i][j] = 1;
    //             continue;
    //         }

    //         int up = 0;
    //         int left = 0;

    //         if (i > 0)
    //             up = dp[i - 1][j];

    //         if (j > 0)
    //             left = dp[i][j - 1];
    //         dp[i][j] = up + left;
    //     }
    // }

    // // The result is stored in bottom-right cell (m-1, n-1).
    // return dp[m - 1][n - 1];
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
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
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n - 1];
}