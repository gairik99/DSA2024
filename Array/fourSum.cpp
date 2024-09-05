#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
int n = nums.size();

// Sort the input array nums
sort(nums.begin(), nums.end());

// Iterate through the array to find quadruplets
for (int i = 0; i < n; i++)
{
    // Skip duplicates for i
    if (i > 0 && nums[i] == nums[i - 1])
        continue;

    for (int j = i + 1; j < n; j++)
    {
        // Skip duplicates for j
        if (j > i + 1 && nums[j] == nums[j - 1])
            continue;

        // Two pointers approach
        int k = j + 1;
        int l = n - 1;

        while (k < l)
        {
            long long sum = nums[i] + nums[j] + nums[k] + nums[l];

            if (sum == target)
            {
                // Found a quadruplet that sums up to target
                vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                ans.push_back(temp);

                // Skip duplicates for k and l
                k++;
                l--;
                while (k < l && nums[k] == nums[k - 1])
                    k++;
                while (k < l && nums[l] == nums[l + 1])
                    l--;
            }
            else if (sum < target)
            {
                k++;
            }
            else
            {
                l--;
            }
        }
    }
}

return ans;
}