#include <bits/stdc++.h>
using namespace std;
// problem link
// https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

long long trappingWater(int arr[], int n)
{
    // code here
    long long res = 0;
    int lMax[n];
    int rMax[n];

    lMax[0] = arr[0];
    for (int i = 1; i < n; i++)
        lMax[i] = max(arr[i], lMax[i - 1]);

    rMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rMax[i] = max(arr[i], rMax[i + 1]);

    // 	for(int i = 1; i < n - 1; i++)
    // 		res = res + (min(lMax[i], rMax[i]) - arr[i]);

    // 	return res;

    for (int i = 1; i < n - 1; i++)
        res = res + (min(lMax[i], rMax[i]) - arr[i]);

    return res;
}