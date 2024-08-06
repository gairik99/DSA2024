#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/next-greater-element-ii/

vector<int> nextGreaterElements(vector<int> &a)
{
    int n = a.size();
    vector<int> v(n, -1);

    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        // we pop out all elements smaller than current element
        while (!st.empty() && (a[i % n] <= st.top()))
        {
            st.pop();
        }

        // if stack is empty means no greater element is there
        // if not empty we make answer at that index equal to top element
        if (!st.empty() && (i < n))
        {
            v[i] = st.top();
        }

        st.push(a[i % n]);
    }

    return v;
}