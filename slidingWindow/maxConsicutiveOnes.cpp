#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/max-consecutive-ones-iii/
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0, j = 0;
    int zeroCount = 0;
    int maxLen = 0;

    while (j < n)
    {
        if (nums[j] == 0)
        {
            zeroCount++;
        }

        while (zeroCount > k)
        {
            if (nums[i] == 0)
            {
                zeroCount--;
            }
            i++;
        }

        maxLen = max(maxLen, j - i + 1);
        j++;
    }

    return maxLen;
}

int longestOnes(vector<int> &nums, int k)
{
    int l = 0, r = 0, max_length = 0, zero_count = 0;
    int n = nums.size();

    while (r < n)
    {
        if (nums[r] == 0)
            zero_count++;

        while (zero_count > k)
        {
            if (nums[l] == 0)
                zero_count--;
            l++;
        }

        if (zero_count <= k)
        {
            max_length = std::max(max_length, r - l + 1);
        }

        r++;
    }

    return max_length;
}