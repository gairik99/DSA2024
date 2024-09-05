#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> nums)
{
    long long n = nums.size();

    // Sum of first n natural numbers
    long long SN = (n * (n + 1)) / 2;

    // Sum of squares of first n natural numbers
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    /*Calculate actual sum (S) and sum
    of squares (S2) of array elements*/
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += nums[i];
        S2 += (long long)nums[i] * (long long)nums[i];
    }

    // Compute the difference values
    long long val1 = S - SN;

    // S2 - S2n = X^2 - Y^2
    long long val2 = S2 - S2N;

    // Calculate X + Y using X + Y = (X^2 - Y^2) / (X - Y)
    val2 = val2 / val1;

    /* Calculate X and Y from X + Y and X - Y
     X = ((X + Y) + (X - Y)) / 2
     Y = X - (X - Y)*/
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    // Return the results as {repeating, missing}
    return {(int)x, (int)y};
}