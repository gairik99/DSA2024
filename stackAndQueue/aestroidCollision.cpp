#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/asteroid-collision/

vector<int> asteroidCollision(vector<int> &as)
{
    stack<int> st;
    for (int i = 0; i < as.size(); i++)
    {
        if (as[i] > 0)
            st.push(as[i]);
        else
        {
            while (!st.empty() && st.top() > 0 && st.top() < abs(as[i]))
                st.pop();

            if (!st.empty() && st.top() == abs(as[i]))
                st.pop();

            else if (st.empty() || st.top() < 0)
                st.push(as[i]);
        }
    }
    vector<int> ans(st.size());
    int l = st.size() - 1;
    while (st.size())
    {
        ans[l--] = st.top();
        st.pop();
    }
    return ans;
}