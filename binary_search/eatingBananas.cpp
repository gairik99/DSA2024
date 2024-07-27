#include <bits/stdc++.h>
using namespace std;
// problem link
// https://bit.ly/3CmCKVI

int findMax(vector<int> &v)
{
    int maxi = INT_MIN;
    int n = v.size();
    // find the maximum:
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

long long calculateTotalHours(vector<int> &v, int hourly)
{
    long long totalH = 0; // Use long long to avoid overflow
    int n = v.size();
    // Find total hours:
    for (int i = 0; i < n; i++)
    {
        totalH += (v[i] + hourly - 1) / hourly; // Equivalent to ceil((double)v[i] / (double)hourly)
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    // Write Your Code Here
    int low = 1, high = *max_element(v.begin(), v.end()), ans = -1;

    // apply binary search:
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long totalH = calculateTotalHours(v, mid);
        if (totalH <= h)
        {
            // ans=high;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = low;
        }
    }
    return low;
}