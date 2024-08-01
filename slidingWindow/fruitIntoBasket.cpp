#include <bits/stdc++.h>
using namespace std;
// problem link
// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

int totalFruits(vector<int> &arr)
{
    int n = arr.size();
    int maxi = 0;
    unordered_map<int, int> m;
    int l = 0, r = 0;
    while (r < n)
    {

        m[arr[r]]++;

        if (m.size() > 2)
        {

            m[arr[l]]--;
            if (m[arr[l]] == 0)
                m.erase(arr[l]);
            l++;
        }

        if (m.size() <= 2)
            maxi = max(maxi, r - l + 1);

        r++;
    }

    return maxi;
}