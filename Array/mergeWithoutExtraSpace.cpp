#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = m - 1;

    // Pointer for nums2 (beginning of valid elements)
    int right = 0;

    /* Swap the elements until nums1[left]
    is smaller than nums2[right]*/
    while (left >= 0 && right < n)
    {

        if (nums1[left] > nums2[right])
        {
            swap(nums1[left], nums2[right]);
            left--, right++;
        }
        // break out of loop if nums1[left] > nums2[right]
        else
            break;
    }

    // Sort nums1 from index 0 to m-1
    sort(nums1.begin() + 0, nums1.begin() + m);
    // nums1.resize(n+m);

    // Sort nums2 from start to end
    sort(nums2.begin(), nums2.end());

    // Put the elements of nums2 in nums1
    for (int i = m; i < n + m; i++)
    {
        nums1[i] = (nums2[i - m]);
    }
}