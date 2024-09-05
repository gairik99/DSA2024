#include <bits/stdc++.h>
using namespace std;

vector<int> printIntersection(vector<int> &arr1, vector<int> &arr2)
{
    // Your code here
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (i > 0 && arr1[i] == arr1[i - 1])
        { // For Handling duplicates
            i++;
            continue;
        }
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        {
            ans.push_back(arr2[j]);
            i++;
            j++;
        }
    }
    return ans;
}