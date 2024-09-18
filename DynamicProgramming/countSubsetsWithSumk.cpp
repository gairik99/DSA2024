#include <bits/stdc++.h>
using namespace std;

int modulo = 1e9 + 7;
int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    /* Base case: If the target sum
    is 0, we found a valid subset*/
    if (target == 0)
        return 1;

    /* Base case: If we have considered all elements
    and the target is still not 0, return 0*/
    if (ind == 0)
        return (arr[0] == target) ? 1 : 0;

    /* If the result for this state
    is already calculated, return it*/
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Exclude the current element
    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    /* Include the current element if
    it doesn't exceed the target*/
    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    /* Store the result in DP table and return
    Also, take modulo for the code to be accepted*/
    return dp[ind][target] = (notTaken + taken) % modulo;
}

int perfectSum(vector<int> &arr, int K)
{
    int n = arr.size();

    // DP array to store the subproblems
    vector<vector<int>> dp(n, vector<int>(K + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (arr[0] <= K)
    {
        dp[0][arr[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= K; target++)
        {
            // Exclude the current element
            int notTaken = dp[ind - 1][target];
            int taken = 0;
            if (arr[ind] <= target)
            {
                taken = (dp[ind - 1][target - arr[ind]]) % modulo;
            }
            dp[ind][target] = (notTaken + taken) % modulo;
        }
    }
    return dp[n - 1][K];
}