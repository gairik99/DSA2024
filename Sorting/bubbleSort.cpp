#include <bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    // Traverse through the array
    for (int i = n - 1; i >= 0; i--)
    {
        // Track if swaps are made
        bool didSwap = false;
        for (int j = 0; j <= i - 1; j++)
        {
            // Swap if next element is smaller
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                didSwap = true;
            }
        }
        /**  Break out of loop
     if no swaps done*/
        if (!didSwap)
        {
            break;
        }
    }
    return nums;
}
