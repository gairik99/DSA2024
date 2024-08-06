#include <bits/stdc++.h>
using namespace std;
// problem link
// https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

int sumSubarrayMins(int N, vector<int> &arr)
{
    // code here
    vector<int> left(N, -1);
    vector<int> right(N, N);

    stack<int> s;
    for (int i = 0; i < N; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            left[i] = s.top();
        }
        s.push(i);
    }

    s = stack<int>();
    for (int i = N - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            right[i] = s.top();
        }
        s.push(i);
    }

    long long res = 0;
    for (int i = 0; i < N; i++)
    {
        int L = i - left[i];
        int R = right[i] - i;
        res += (arr[i] * L * R); // L+1 to R-1 is the range where arr[i] is minimum you see
        res %= 1000000007;
    }
    return res;
}