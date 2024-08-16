#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/binary-subarrays-with-sum/

double helper(double x, int n)
{
    if (n == 0)
        return 1.0000;
    double ans = myPow(x, n / 2);
    if (n % 2)
        return ans * ans * x;
    return ans * ans;
}
double myPow(double x, int n)
{
    // your code goes here
    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }
    return helper(x, n);
}