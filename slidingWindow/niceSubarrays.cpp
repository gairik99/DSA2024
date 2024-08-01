#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

int helper(vector<int> arr, int goal)
{
    if (goal < 0)
        return 0;
    int n = arr.size(), low = 0, high = 0, count = 0, sum = 0;
    while (high < n)
    {
        sum += arr[high] % 2;
        while (sum > goal)
        {
            sum -= arr[low] % 2;
            low++;
        }
        count += (high - low + 1);
        high++;
    }
    return count;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    return helper(nums, k) - helper(nums, k - 1);
}