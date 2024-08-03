#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/minimum-window-substring/

string minWindow(string s, string t)
{
    int l = 0, r = 0;
    int n = s.size(), m = t.size();
    int cnt = 0, minLen = 1e7;
    int startInd = -1;
    map<char, int> mp;
    for (int i = 0; i < m; i++)
        mp[t[i]]++;

    while (r < n)
    {
        if (mp[s[r]] > 0)
            cnt++;
        mp[s[r]]--;

        while (cnt == m)
        {
            if (r - l + 1 < minLen)
            {
                minLen = (r - l + 1);
                startInd = l;
            }

            mp[s[l]]++;
            if (mp[s[l]] > 0)
            {
                cnt--;
            }
            l++;
        }
        r++;
    }
    return startInd == -1 ? "" : s.substr(startInd, minLen);
}