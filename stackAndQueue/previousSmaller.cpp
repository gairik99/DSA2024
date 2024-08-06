#include <bits/stdc++.h>
using namespace std;
// problem link
// https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1

vector<int> leftSmaller(int n, int a[])
{
    // code here
    stack<int> st;
    vector<int> ans(n, -1);
    st.push(a[0]);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && st.top() >= a[i])
            st.pop();

        if (!st.empty() && a[i] >= st.top())
            ans[i] = st.top();

        st.push(a[i]);
    }
    return ans;
}