#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    // Temporary array to store merged elements
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Loop until subarrays are exhausted
    while (left <= mid && right <= high)
    {
        // Compare left and right elements
        if (arr[left] <= arr[right])
        {
            // Add left element to temp
            temp.push_back(arr[left]);
            // Move left pointer
            left++;
        }
        else
        {
            // Add right element to temp
            temp.push_back(arr[right]);
            // Move right pointer
            right++;
        }
    }

    // Adding the remaining elements of left half
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Adding the remaining elements of right half
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Transferring the sorted elements to arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

vector<int> mergeSortHelper(vector<int> &arr, int low, int high)
{
    // Base case: if the array has only one element
    if (low >= high)
        return arr;
    // Find the middle index
    int mid = (low + high) / 2;
    // Recursively sort the left half
    mergeSortHelper(arr, low, mid);
    // Recursively sort the right half
    mergeSortHelper(arr, mid + 1, high);
    // Merge the sorted halves
    merge(arr, low, mid, high);
    return arr;
}

vector<int> mergeSort(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    return mergeSortHelper(nums, low, high);
}