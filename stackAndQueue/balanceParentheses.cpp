#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/valid-parentheses/

bool isValid(string s)
{
    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {

        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            st.push(s[i]);
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                return false;
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
                st.pop();
            else
                return false;
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                return false;
        }
    }

    return st.empty();
}