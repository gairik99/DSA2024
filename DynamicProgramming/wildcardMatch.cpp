#include <bits/stdc++.h>
using namespace std;

bool isAllStars(string S1, int i)
{
    for (int j = 0; j <= i; j++)
    {
        if (S1[j] != '*')
            return false;
    }
    return true;
}

/* Function to check if S1 matches S2
using wildcard pattern matching*/
bool wildcardMatchingUtil(string S1, string S2, int i, int j, vector<vector<int>> &dp)
{
    // Base Cases
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
        return isAllStars(S1, i);

    /* If the result for this state has
    already been calculated, return it*/
    if (dp[i][j] != -1)
        return dp[i][j] == 1;

    // bool result;

    /* If the characters at the current
    positions match or S1 has a '?'*/
    if (S1[i] == S2[j] || S1[i] == '?')
    {
        return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
    }
    if (S1[i] == '*')
    {
        /* Two options: either '*' represents an
        empty string or it matches a character in S2*/
        return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
    }
    else
    {
        return dp[i][j] = false;
    }
}
bool wildCard(string str, string pat)
{
    int n = str.size();
    int m = pat.size();

    /* Create a DP table for
    memoization, initialized with -1*/
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return wildcardMatchingUtil(str, pat, n - 1, m - 1, dp);
}