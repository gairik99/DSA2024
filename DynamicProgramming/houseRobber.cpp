#include <bits/stdc++.h>
using namespace std;

int func(int ind, vector<int> &arr, vector<int> &dp)
{

    // Base case
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    // Choosing the current element
    int pick = arr[ind] + func(ind - 2, arr, dp);

    // Skipping the current element
    int nonPick = 0 + func(ind - 1, arr, dp);

    /* Store the result in dp
    array and return the maximum */
    return dp[ind] = max(pick, nonPick);
}

int houseRobber(vector<int> &money)
{
    int n = money.size();
    vector<int> arr1;
    vector<int> arr2;

    // If array has only one element, return that
    if (n == 1)
        return money[0];

    for (int i = 0; i < n; i++)
    {
        /*Store every element in
        arr1 except the last element*/
        if (i != n - 1)
            arr1.push_back(money[i]);

        /*Store every element in
        arr2 except the first element*/
        if (i != 0)
            arr2.push_back(money[i]);
    }

    // Initialize the dp array with -1
    vector<int> dp(n - 1, -1);
    int ans1 = func(arr1.size() - 1, arr1, dp);

    vector<int> dp1(n - 1, -1);
    int ans2 = func(arr2.size() - 1, arr2, dp1);

    // Return the maximum of an1 and ans2
    return max(ans1, ans2);
}