#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the given array.
    unordered_map<int, int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++)
    {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int needed = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[needed];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}