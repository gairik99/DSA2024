#include <bits/stdc++.h>
using namespace std;

int func(int ind, int n, vector<int> &price, vector<vector<int>> &dp)
{

    if (n == 0)
        return 0;

    if (ind == 0)
    {
        return price[0] * n;
    }

    if (dp[ind][n] != -1)
    {
        return dp[ind][n];
    }

    int notTaken = func(ind - 1, n, price, dp);

    int rodLength = ind + 1;
    int taken = INT_MIN;
    if (rodLength <= n)
    {
        taken = price[ind] + func(ind, n - rodLength, price, dp);
    }
    return dp[ind][n] = max(notTaken, taken);
}

int RodCutting(vector<int> price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return func(n - 1, n, price, dp);
}