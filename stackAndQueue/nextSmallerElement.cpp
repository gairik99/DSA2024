#include <bits/stdc++.h>
using namespace std;
// problem link
// https://www.naukri.com/code360/problems/next-smaller-element_1112581

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;

    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {

        int curr = arr[i];

        while (!s.empty() && s.top() >= curr)
        {

            s.pop();
        }

        if (!s.empty())
            ans[i] = s.top();

        s.push(curr);
    }

    return ans;
}