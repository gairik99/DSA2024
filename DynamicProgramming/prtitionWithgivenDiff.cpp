#include <bits/stdc++.h>
using namespace std;

int mod = (int)1e9 + 7;
int countPartitionsUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case: If we are at the first element.
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }

    // Return the result if it has already been computed.
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);
    int taken = 0;
    if (arr[ind] <= target)
        taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = (notTaken + taken) % mod;
}
int countPartitions(int n, int diff, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totSum += arr[i];
    }

    if (totSum - diff < 0)
        return 0;
    if ((totSum - diff) % 2 == 1)
        return 0;

    // Calculate the target sum for one of the subsets.
    int s2 = (totSum - diff) / 2;
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return countPartitionsUtil(n - 1, s2, arr, dp);
}