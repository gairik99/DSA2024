#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    // Your code here
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    long long ans = 0;
    while (pq.size() > 1)
    {
        long long mini1 = pq.top();
        pq.pop();

        long long mini2 = pq.top();
        pq.pop();

        pq.push(mini1 + mini2);
        ans += (mini1 + mini2);
    }

    return ans;
}
