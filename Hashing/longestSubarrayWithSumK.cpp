#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        // calculate the prefix sum till index i
        sum += nums[i];

        // if the sum equals k, update maxLen
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e., sum - k
        int rem = sum - k;

        // calculate the length and update maxLen
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // update the map if sum is not already present
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}