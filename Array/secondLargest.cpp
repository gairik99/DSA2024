#include <bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int> &nums)
{
    // your code goes here
    if (nums.size() < 2)
    {

        /* If true, return -1 indicating there
        is no second largest element*/
        return -1;
    }

    /*Initialize variables to store the
    largest and second largest elements*/
    int large = INT_MIN;
    int second_large = INT_MIN;

    /* Single traversal to find the
    largest and second largest elements*/
    for (int i = 0; i < nums.size(); i++)
    {

        if (nums[i] > large)
        {
            second_large = large;
            large = nums[i];
        }
        else if (nums[i] > second_large && nums[i] != large)
        {
            second_large = nums[i];
        }
    }

    // Return the second largest element
    return second_large == INT_MIN ? -1 : second_large;
}