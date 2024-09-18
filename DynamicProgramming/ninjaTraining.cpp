#include <bits/stdc++.h>
using namespace std;

int func(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    // Base case
    if (day == 0)
    {
        int maxi = 0;

        /* Calculate the maximum points for the first day
        by choosing an activity different from last one*/
        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        // Return the maximum points
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;

    // Iterate through activities for the current day
    for (int i = 0; i <= 2; i++)
    {
        if (i != last)
        {

            /* Calculate the points for the current activity
            and add it to the maximum points obtained so far */
            int activity = points[day][i] + func(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }

    // Return the maximum points
    return dp[day][last] = maxi;
}

int ninjaTraining(vector<vector<int>> &points)
{
    // int day = matrix.size()-1;
    // int last = 3;
    // vector<vector<int>>dp(day+1,vector<int>(4,-1));
    // return func(day, last, matrix,dp);
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Base case: First day
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];

    // Fill the dp table
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = points[i][0] + max(dp[i - 1][1], dp[i - 1][2]); // If today is activity 0, yesterday was activity 1 or 2
        dp[i][1] = points[i][1] + max(dp[i - 1][0], dp[i - 1][2]); // If today is activity 1, yesterday was activity 0 or 2
        dp[i][2] = points[i][2] + max(dp[i - 1][0], dp[i - 1][1]); // If today is activity 2, yesterday was activity 0 or 1
    }

    // The maximum merit points after the last day
    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}
