#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int jumpOne = solve(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int jumpTwo = INT_MAX;
    if (ind > 1)
        jumpTwo = solve(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

    return dp[ind] = min(jumpOne, jumpTwo);
}

int frogJump(vector<int> &heights)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    // return solve(n-1,heights,dp);
    // dp[0]=0;
    // for(int i=1;i<n;i++){
    //     int jumpOne=dp[i-1]+abs(heights[i]-heights[i-1]);
    //     int jumpTwo=INT_MAX;
    //     if(i>1)
    //     jumpTwo=dp[i-2]+abs(heights[i]-heights[i-2]);
    //     dp[i]=min(jumpOne,jumpTwo);
    // }
    // return dp[n-1];
    int prev2 = 0, prev1 = 0, curr = 0;
    for (int i = 1; i < n; i++)
    {
        int jumpOne = prev1 + abs(heights[i] - heights[i - 1]);
        int jumpTwo = INT_MAX;
        if (i > 1)
            jumpTwo = prev2 + abs(heights[i] - heights[i - 2]);
        curr = min(jumpOne, jumpTwo);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}