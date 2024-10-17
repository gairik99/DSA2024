#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }

    // Check if the subproblem is already solved
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++)
    {
        int ans = cuts[j + 1] - cuts[i - 1] + func(i, ind - 1, cuts, dp) + func(ind + 1, j, cuts, dp);

        mini = min(mini, ans);
    }
    // Return the result
    return dp[i][j] = mini;
}
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Create a DP table to store calculated values.
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));

    // Call the recursive function to find minimum cost.
    return func(1, c, cuts, dp);
}