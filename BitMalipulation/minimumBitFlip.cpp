#include <bits/stdc++.h>
using namespace std;

int minBitsFlip(int start, int goal)
{
    // Your code goes here
    int num = start ^ goal;

    /* Variable to count
    number of set bits */
    int count = 0;

    while (num)
    {
        /* Update count if the
        rightmost bit is set */
        count++;
        num = (num - 1) & num;

        /* Shift the number every
        time by 1 place */
        // num = num >> 1;
    }
    return count;
}