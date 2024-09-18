#include <bits/stdc++.h>
using namespace std;

int func(int ind, vector<int> &arr, vector<int> &dp)
{
    // Base cases
    if (ind == 0)
        return arr[ind];
    // if (ind < 0)
    //     return 0;

    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    // Choosing the current element

    int pick = arr[ind];
    if (ind > 1)
        pick += func(ind - 2, arr, dp);

    // Skipping the current element
    int nonPick = 0 + func(ind - 1, arr, dp);

    /* Store the result in dp
    array and return the maximum */
    return dp[ind] = max(pick, nonPick);
}
int nonAdjacent(vector<int> &nums)
{
    int ind = nums.size();

    // Initialize the dp array with -1
    vector<int> dp(ind, -1);

    // Return the maximum sum
    //  return func(ind-1, nums, dp);
    //  dp[0]=nums[0];
    //  for(int i=1;i<ind;i++){
    //      int pick=nums[i];
    //      if(i>1)pick+=dp[i-2];
    //      int nonPick=dp[i-1];
    //      dp[i]=max(pick,nonPick);
    //  }
    //  return dp[ind-1];
    int prev1 = nums[0], prev2 = 0, curr = 0;
    for (int i = 1; i < ind; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += prev2;
        int nonPick = prev1;
        curr = max(pick, nonPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}