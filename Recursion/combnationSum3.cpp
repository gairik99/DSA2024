#include <bits/stdc++.h>
using namespace std;

void func(int sum, int last, int k, vector<int> &nums, vector<vector<int>> &ans)
{
    if (sum == 0 && nums.size() == k)
        ans.push_back(nums);

    if (sum < 0 || nums.size() > k)
        return;
    for (int i = last; i <= 9; i++)
    {
        if (sum >= i)
        {
            nums.push_back(i);
            func(sum - i, i + 1, k, nums, ans);
            nums.pop_back();
        }

        else
            return;
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    // your code goes here
    vector<vector<int>> ans;
    vector<int> nums;
    // Call the recursive function with initial parameters
    func(n, 1, k, nums, ans);
    return ans;
}