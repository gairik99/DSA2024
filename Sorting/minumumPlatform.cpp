#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int> &arr, vector<int> &dep)
{
    // Your code here
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int ans = 1;
    int count = 1;
    int i = 1;
    int j = 0;

    while (i < arr.size() && j < arr.size())
    {

        if (arr[i] <= dep[j])
        {
            count++;
            i++;
        }

        else
        {
            count--;
            j++;
        }
        ans = max(count, ans);
    }

    return ans;
}
