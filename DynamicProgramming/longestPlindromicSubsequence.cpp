#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    // Declare a 2D DP array to store length of the LCS
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    // Fill in the DP array
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }
    // The value at dp[n][m] contains length of the LCS
    return dp[n][m];
}
int longestPalinSubseq(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    return lcs(s, t);
}