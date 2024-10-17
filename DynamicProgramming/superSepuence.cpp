#include <bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    // Create a DP table with dimensions (n+1) x (m+1) initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row and column of the DP table
    // for (int i = 0; i <= n; i++) {
    //     dp[i][0] = 0;
    // }
    // for (int i = 0; i <= m; i++) {
    //     dp[0][i] = 0;
    // }

    // Fill the DP table
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (str1[ind1 - 1] == str2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    // Reconstruct the shortest supersequence from the DP table
    int len = dp[n][m];
    int i = n;
    int j = m;

    // int index = len - 1;
    string ans = "";

    // Build the shortest supersequence by backtracking
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans += str1[i - 1];
            // index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += str1[i - 1];
            i--;
        }
        else
        {
            ans += str2[j - 1];
            j--;
        }
    }

    // Add remaining characters from str1 or str2
    while (i > 0)
    {
        ans += str1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += str2[j - 1];
        j--;
    }

    // Reverse the result since we built it backwards
    reverse(ans.begin(), ans.end());
    return ans;
}