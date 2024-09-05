#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int N)
{
    // Your code here
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = -1;
        }
    }
    unordered_map<int, int> s;

    int res = 0;
    int pre_sum = 0;

    for (int i = 0; i < N; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == 0)
        {
            res = i + 1;
        }
        if (s.find(pre_sum) != s.end())
        {
            res = max(res, i - s[pre_sum]);
        }

        if (s.find(pre_sum) == s.end())
        {
            s.insert({pre_sum, i});
        }
    }
    return res;
}