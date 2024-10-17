#include <bits/stdc++.h>
using namespace std;

int func(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
{
    // Base case
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + func(s1, s2, ind1 - 1, ind2 - 1, dp);
    else
        return dp[ind1][ind2] = max(func(s1, s2, ind1, ind2 - 1, dp), func(s1, s2, ind1 - 1, ind2, dp));
}

int lcs(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    // Return the result
    return func(str1, str2, n - 1, m - 1, dp);
}