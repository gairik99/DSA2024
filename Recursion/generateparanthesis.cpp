#include <bits/stdc++.h>
using namespace std;

void func(int open, int close, int n, string s, vector<string> &ans)
{
    // Base case: if the number of open and close parentheses used
    // is equal to the total number of pairs, add the string to the result.
    if (open == close && (open + close) == 2 * n)
    {
        ans.push_back(s);
        return;
    }

    // If the number of open parentheses used is less than the total
    // number of pairs, add an open parenthesis and call the function recursively.
    if (open < n)
    {
        func(open + 1, close, n, s + '(', ans);
    }

    // If the number of close parentheses used is less than the number
    // of open parentheses, add a close parenthesis and call the function recursively.
    if (close < open)
    {
        func(open, close + 1, n, s + ')', ans);
    }
}
vector<string> generateParenthesis(int n)
{
    // your code goes here
    vector<string> ans;
    func(0, 0, n, "", ans);
    return ans;
}