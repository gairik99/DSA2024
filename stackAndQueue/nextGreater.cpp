#include <bits/stdc++.h>
using namespace std;
// problem link
// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here
    vector<long long> ans(n, -1);
    stack<long long> st;
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        if (!st.empty() && st.top() > arr[i])
            ans[i] = st.top();

        st.push(arr[i]);
    }
    return ans;
}