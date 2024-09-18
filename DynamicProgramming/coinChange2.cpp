#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int func(vector<int> &arr, int ind, int T, vector<vector<int>> &dp)
{
    // Base case: if we're at the first element
    if (ind == 0)
    {
        return (T % arr[0] == 0);
    }

    if (dp[ind][T] != -1)
        return dp[ind][T];

    int notTaken = func(arr, ind - 1, T, dp) % mod;
    ;
    int taken = 0;
    if (arr[ind] <= T)
        taken = func(arr, ind, T - arr[ind], dp) % mod;
    return dp[ind][T] = (notTaken + taken) % mod;
}

int count(vector<int> &coins, int N, int amount)
{
    vector<vector<int>> dp(N, vector<int>(amount + 1, -1));
    return func(coins, N - 1, amount, dp);
}