#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/longest-repeating-character-replacement/

int characterReplacement(string s, int k)
{
    unordered_map<char, int> alphabets;
    int ans = 0;
    int left = 0;
    int right = 0;
    int maxf = 0;

    while (right < s.size())
    {
        alphabets[s[right]]++;
        maxf = max(maxf, alphabets[s[right]]);

        if ((right - left + 1) - maxf > k)
        {
            alphabets[s[left]] -= 1;
            left++;
        }
        else
        {
            ans = max(ans, (right - left + 1));
        }
        right++;
    }

    return ans;
}