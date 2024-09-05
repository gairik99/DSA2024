#include <bits/stdc++.h>
using namespace std;

void sortZeroOneTwo(vector<int> &nums)
{
    int zero = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[zero]);
            zero++;
            mid++;
        }
        else if (nums[mid] == 1)
            mid++;
        else
        {
            swap(nums[high], nums[mid]);
            high--;
        }
    }
}
