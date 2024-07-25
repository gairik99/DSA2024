#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n)
{
    // Write your code here.
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int lowerBound(vector<int> &arr, int n, int x)
{
    // Write your code here

    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}


int main(){
    vector<int>v={1,2,2,3,9,11,15,19};
    cout<<lowerBound(v,8,9);
}