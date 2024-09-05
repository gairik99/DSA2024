#include <bits/stdc++.h>
using namespace std;

void kthLargest(int arr[], int n, int k)
{
    // your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    // vector<int>ans;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);

        if (k > pq.size())
        {
            cout << -1 << " ";
        }
        else if (k == pq.size())
        {
            cout << pq.top() << " ";
        }
        else if (k < pq.size())
        {
            pq.pop();
            cout << pq.top() << " ";
        }
    }
}