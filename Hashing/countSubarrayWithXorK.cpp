#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> &nums, int k)
{
    int xr = 0, cnt = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    for (auto &it : nums)
    {
        xr = xr ^ it;
        int need = xr ^ k;
        if (mpp.find(need) != mpp.end())
            cnt += mpp[need];
        mpp[xr]++;
    }
    return cnt;
}