#include <bits/stdc++.h>
using namespace std;

int closer(int arr[], int n, int x)
{
    // Your code here
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if x is at mid
        if (arr[mid] == x)
            return mid;
        // Check if x is at mid-1
        if (mid > 0 && arr[mid - 1] == x)
            return mid - 1;
        // Check if x is at mid+1
        if (mid < n - 1 && arr[mid + 1] == x)
            return mid + 1;

        // Adjust the search boundaries
        if (arr[mid] < x)
        {
            low = mid + 2; // Move right since x > arr[mid]
        }
        else
        {
            high = mid - 2; // Move left since x < arr[mid]
        }
    }

    // If element is not found
    return -1;
}