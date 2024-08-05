#include <bits/stdc++.h>
using namespace std;
// problem link
// https://shorturl.at/txB0A

bool isOperator(char ch)
{
    if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
        return false;
    return true;
}

string postToPre(string post_exp)
{
    // Write your code here
    stack<string> st;
    for (auto ch : post_exp)
    {
        if (isOperator(ch))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push(ch + op2 + op1);
        }
        else
        {
            st.push(string(1, ch));
        }
    }
    return st.top();
}