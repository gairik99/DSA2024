#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    // Check if the subproblem is already solved
    if (dp[i][j] != -1)
        return dp[i][j];

    int maxCoins = INT_MIN;

    // Iterate through each balloon to burst last
    for (int k = i; k <= j; k++)
    {
        /* Calculate the coins obtained
        by bursting the k-th balloon last*/
        int coins = nums[i - 1] * nums[k] * nums[j + 1];

        /* Recursively calculate the maximum
        coins for the remaining balloons*/
        int remainingCoins = func(i, k - 1, nums, dp) + func(k + 1, j, nums, dp);

        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);
    }
    // Return the result
    return dp[i][j] = maxCoins;

    // Return the result
    return maxCoins;
}
int maxCoins(vector<int> &nums)
{
    // your code goes here
    int n = nums.size();

    // Add 1 to the beginning and end of nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    // Create a DP array for memoization
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

    // Call the helper function to compute maximum coins
    return func(1, n, nums, dp);
}