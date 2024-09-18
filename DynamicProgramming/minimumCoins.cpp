#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;
/* Function to calculate the minimum number
of elements to form the target sum*/
int func(vector<int> &arr, int ind, int T, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (T % arr[0] == 0)
            return T / arr[0];
        else
            return 1e9;
    }
    if (dp[ind][T] != -1)
        return dp[ind][T];
    int notTaken = 0 + func(arr, ind - 1, T, dp);

    int taken = 1e9;
    if (arr[ind] <= T)
        taken = 1 + func(arr, ind, T - arr[ind], dp);
    return dp[ind][T] = min(notTaken, taken);
}

public:
int MinimumCoins(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = func(coins, n - 1, amount, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
}
