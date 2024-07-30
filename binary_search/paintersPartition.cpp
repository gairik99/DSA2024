#include <bits/stdc++.h>
using namespace std;

// problem link
// https://bit.ly/3XM8oFS

int countPainters(vector<int> &boards, int time)
{
    int n = boards.size(); // size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++)
    {
        if (boardsPainter + boards[i] <= time)
        {
            // allocate board to current painter
            boardsPainter += boards[i];
        }
        else
        {
            // allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    // Apply binary search:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}