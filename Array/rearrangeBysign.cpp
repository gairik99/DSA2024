#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();

    // Initialize a result vector of size n
    vector<int> ans(n, 0);

    // Initialize indices for positive and negative elements
    int posIndex = 0, negIndex = 1;

    // Traverse through each element in nums
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {

            /* If current element is negative, place
            it at the next odd index in ans*/
            ans[negIndex] = nums[i];

            // Move to the next odd index
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = nums[i];

            // Move to the next even index
            posIndex += 2;
        }
    }

    // Return the rearranged array
    return ans;
}