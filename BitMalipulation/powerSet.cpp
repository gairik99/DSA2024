#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int> &nums)
{
    // your code goes here
    int n = nums.size();
    n = pow(2, n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> vec;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i & 1 << j)
                vec.push_back(nums[j]);
        }
        ans.push_back(vec);
    }
    return ans;
}
