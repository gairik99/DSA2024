#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/binary-subarrays-with-sum/

int helper(vector<int> arr, int goal)
{
    if (goal < 0)
        return 0;
    int n = arr.size(), low = 0, high = 0, count = 0, sum = 0;
    while (high < n)
    {
        sum += arr[high];
        while (sum > goal)
        {
            sum -= arr[low];
            low++;
        }
        count += (high - low + 1);
        high++;
    }
    return count;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return helper(nums, goal) - helper(nums, goal - 1);
}