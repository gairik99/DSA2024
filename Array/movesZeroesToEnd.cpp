#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &arr)
{
    int nonZero = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            swap(arr[i], arr[nonZero++]);
    }
}