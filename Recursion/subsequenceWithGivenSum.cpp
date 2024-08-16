#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &nums, int k, int sum, int ind)
{
    if (ind == nums.size())
    {
        if (k == sum)
            return true;
        return false;
    }
    if (sum == k)
        return true;
    bool left = false;
    if (sum < k)
    {
        sum += nums[ind];
        left = helper(nums, k, sum, ind + 1);
        sum -= nums[ind];
    }
    bool right = helper(nums, k, sum, ind + 1);
    if (left || right)
        return true;
    return false;
}
bool checkSubsequenceSum(vector<int> &nums, int k)
{
    // your code goes here
    return helper(nums, k, 0, 0);
}