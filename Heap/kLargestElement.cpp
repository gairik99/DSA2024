#include <bits/stdc++.h>
using namespace std;

void firstKElements(int arr[], int n, int k)
{

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < k; i++)
    {
        minHeap.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (minHeap.top() > arr[i])
            continue;
        else
        {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    while (minHeap.empty() == false)
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}