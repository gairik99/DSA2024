#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &nums)
{
    vector<int> ans;
    ans.push_back(nums[nums.size() - 1]);
    int maxi = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] > maxi)
        {
            maxi = nums[i];
            ans.push_back(maxi);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}