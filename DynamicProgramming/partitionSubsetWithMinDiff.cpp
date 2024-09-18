#include <bits/stdc++.h>
using namespace std;

int minDifference(vector<int> &arr, int n)
{
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    // Initialize a DP table to store the results of the subset sum problem
    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

    // Base case: If no elements are selected (sum is 0), it's a valid subset
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // Initialize the first row based on the first element of the array
    if (arr[0] <= totSum)
        dp[0][arr[0]] = true;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= totSum; target++)
        {
            // Exclude the current element
            bool notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}