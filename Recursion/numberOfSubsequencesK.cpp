#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int k, int sum, int ind)
{
    if (ind == nums.size())
    {
        if (k == sum)
            return 1;
        return 0;
    }
    if (sum == k)
        return 1;
    int left = 0;
    if (sum < k)
    {
        sum += nums[ind];
        left = helper(nums, k, sum, ind + 1);
        sum -= nums[ind];
    }
    int right = helper(nums, k, sum, ind + 1);
    return left + right;
}
int countSubseqenceWithTargetSum(vector<int> &nums, int k)
{
    // your code goes here
    return helper(nums, k, 0, 0);
}