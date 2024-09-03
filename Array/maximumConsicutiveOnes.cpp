#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int ones = 0, maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i])
            ones++;
        else
        {
            maxi = max(maxi, ones);
            ones = 0;
        }
    }
    return max(ones, maxi);
}