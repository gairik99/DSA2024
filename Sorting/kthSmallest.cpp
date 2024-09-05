#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    // code here
    priority_queue<int> pq;

    // Iterate through the array elements
    for (int i = l; i <= r; i++)
    {
        // Push the current element onto the max heap
        pq.push(arr[i]);

        // If the size of the max heap exceeds K, remove the largest element
        if (pq.size() > k)
            pq.pop();
    }

    // Return the Kth smallest element (top of the max heap)
    return pq.top();
}