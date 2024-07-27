#include <bits/stdc++.h>
using namespace std;

// problem link
// https://bit.ly/3J5dBCJ

int floorSqrt(int n)
{
    int low = 1, high = n;
    // Binary search on the answers:
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n))
        {
            // eliminate the left half:
            low = mid + 1;
        }
        else
        {
            // eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}