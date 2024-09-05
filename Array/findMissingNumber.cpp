#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int xor1 = 0, xor2 = 0;

    // Calculate XOR of all array elements
    for (int i = 0; i < nums.size(); i++)
    {
        xor1 = xor1 ^ (i + 1) ^ nums[i];
    }

    // XOR of xor1 and xor2 gives missing number
    return xor1;
}