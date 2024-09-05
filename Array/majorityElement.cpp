#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int count = 0, element = -1;
    ;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            count++;
            element = nums[i];
        }
        else if (nums[i] == element)
            count++;
        else
            count--;
    }

    count = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] == element)
            count++;

    if (count > nums.size() / 2)
        return element;
    return -1;
}