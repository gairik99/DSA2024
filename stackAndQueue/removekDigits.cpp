#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/remove-k-digits/
string removeKdigits(string num, int k)
{
    int n = num.size();
    stack<char> s;

    for (char digit : num)
    {
        while (!s.empty() && k > 0 && s.top() > digit)
        {
            s.pop();
            k--;
        }
        s.push(digit);
    }

    // Remove the remaining digits if k > 0
    while (k > 0 && !s.empty())
    {
        s.pop();
        k--;
    }

    // Construct the result string
    string ans = "";
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    // Reverse the result string
    reverse(ans.begin(), ans.end());

    // Remove leading zeros
    int i = 0;
    while (i < ans.size() && ans[i] == '0')
    {
        i++;
    }
    ans = ans.substr(i);

    // If the result string is empty, return "0"
    return ans.empty() ? "0" : ans;
}