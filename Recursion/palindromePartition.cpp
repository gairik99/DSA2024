#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void dfs(int ind, string &s, vector<string> &path, vector<vector<string>> &ans)
{
    if (ind == s.size())
    {
        ans.push_back(path);
        return;
    }
    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(s, ind, i))
        {
            path.push_back(s.substr(ind, i - ind + 1));
            dfs(i + 1, s, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> path;
    dfs(0, s, path, res);
    return res;
}