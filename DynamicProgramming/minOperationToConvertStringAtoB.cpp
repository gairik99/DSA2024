#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the base cases
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {

            // Characters match, increment LCS length
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            /* Characters don't match, consider
            the maximum from left or above*/
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }
    // Return the length of Longest Common Subsequence
    return dp[n][m];
}

int minOperations(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    /* Calculate the length of the longest
    common subsequence between str1 and str2*/
    int k = lcs(str1, str2);

    /* Calculate the minimum operations
    required to convert str1 to str2*/
    return (n - k) + (m - k);
}