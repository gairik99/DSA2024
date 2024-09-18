#include <bits/stdc++.h>
using namespace std;

int helper(int ind, int k, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int steps = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (ind - i >= 0)
        {
            int jumps = helper(ind - i, k, heights, dp) + abs(heights[ind] - heights[ind - i]);
            steps = min(steps, jumps);
        }
    }
    return dp[ind] = steps;
}

int frogJump(vector<int> &heights, int k)
{
    int ind = heights.size();
    vector<int> dp(ind, -1);
    // return helper(ind-1,k,heights,dp);
    dp[0] = 0;

    // Loop through the array
    for (int i = 1; i < ind; i++)
    {
        int mnSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            // int jump=0;
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                mnSteps = min(mnSteps, jump);
            }
        }
        dp[i] = mnSteps;
    }
    return dp[ind - 1];
}