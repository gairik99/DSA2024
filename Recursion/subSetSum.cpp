#include <bits/stdc++.h>
using namespace std;

void func(int ind, int sum, vector<int> &nums, vector<int> &ans)
{
    // Base case: if index reaches the end of the nums vector
    if (ind == nums.size())
    {
        // Add the current sum to the ans vector
        ans.push_back(sum);
        return;
    }
    // Recursively include the current element in the sum
    func(ind + 1, sum + nums[ind], nums, ans);
    // Recursively exclude the current element from the sum
    func(ind + 1, sum, nums, ans);
}

vector<int> subsetSums(vector<int> &nums)
{
    // your code goes here
    vector<int> ans;
    // Start the recursion with index 0 and initial sum 0
    func(0, 0, nums, ans);
    return ans;
}