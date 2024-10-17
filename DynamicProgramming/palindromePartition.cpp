#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int minPartitions(int i, int n, string &str, vector<int> &dp)
{
    // Base case: If we've reached the end of string.
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, str))
        {
            int cost = 1 + minPartitions(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
int minCut(string s)
{
    // your code goes here
    int n = s.size();
    vector<int> dp(n, -1);
    return minPartitions(0, n, s, dp) - 1;
}