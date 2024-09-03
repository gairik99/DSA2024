#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j >= low && arr[j] > pivot)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

vector<int> quickSortHelper(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return arr;
    int pivot = partition(arr, low, high);
    quickSortHelper(arr, low, pivot - 1);
    quickSortHelper(arr, pivot + 1, high);
    return arr;
}
vector<int> quickSort(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    return quickSortHelper(nums, low, high);
}