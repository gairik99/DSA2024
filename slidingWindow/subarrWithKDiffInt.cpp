#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/subarrays-with-k-different-integers/

int helper(vector<int> arr, int goal)
{
    if (goal < 0)
        return 0;
    int n = arr.size(), low = 0, high = 0, count = 0;
    unordered_map<int, int> mpp;
    while (high < n)
    {
        mpp[arr[high]]++;
        while (mpp.size() > goal)
        {
            mpp[arr[low]]--;
            if (mpp[arr[low]] == 0)
                mpp.erase(arr[low]);
            low++;
        }
        count += (high - low + 1);
        high++;
    }
    return count;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return helper(nums, k) - helper(nums, k - 1);
}