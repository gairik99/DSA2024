#include <bits/stdc++.h>
using namespace std;
// problem link
// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

int longestKSubstr(string s, int k)
{
    // your code here
    int cnt = 0, maxi = 0, n = s.size();
    map<int, int> mp;
    int l = 0, r = 0;
    while (r < n)
    {
        mp[s[r]]++;

        if (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }
        if (mp.size() == k)
        {
            maxi = max(maxi, r - l + 1);
        }
        r++;
    }
    if (maxi == 0)
        return -1;
    return maxi;
}