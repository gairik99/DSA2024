#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{

    vector<vector<int>> ans;

    int n = nums.size();

    // Sort the input array nums
    sort(nums.begin(), nums.end());

    // Iterate through the array to find triplets
    for (int i = 0; i < n; i++)
    {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Two pointers approach
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                // Found a triplet that sums up to target
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);

                // Skip duplicates
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }

    return ans;
}