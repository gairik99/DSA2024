#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/online-stock-span/

int next(int price)
{
    if (s.size() == 0)
    {
        s.push({price, 1});
        return 1;
    }
    int c = 1;
    while (!s.empty() && s.top().first <= price)
    {
        c += s.top().second;
        s.pop();
    }
    s.push({price, c});
    return c;
}