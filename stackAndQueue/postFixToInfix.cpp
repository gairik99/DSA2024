#include <bits/stdc++.h>
using namespace std;
// problem link
// https://shorturl.at/kyMoz

bool isOperator(char ch)
{
    if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
        return false;
    return true;
}

string postToInfix(string exp)
{
    // Write your code here
    stack<string> st;
    for (auto ch : exp)
    {
        if (isOperator(ch))
        {

            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push('(' + op2 + ch + op1 + ')');
        }
        else
        {
            st.push(string(ch));
        }
    }
    return st.top();
}
