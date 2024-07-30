#include <bits/stdc++.h>

int kthElement(vector<int> &nums1, vector<int> &nums2, int n1, int n2, int k)
{

    if (n1 > n2)
        return kthElement(nums2, nums1, n2, n1, k);

    int low = max(0, k - n2), high = min(k, n1);

    int left = k;

    int n = n1 + n2;

    while (low <= high)
    {

        int mid1 = (low + high) / 2;

        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;

        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 >= 1)
            l1 = nums1[mid1 - 1];

        if (mid2 >= 1)
            l2 = nums2[mid2 - 1];

        if (mid1 < n1)
            r1 = nums1[mid1];

        if (mid2 < n2)
            r2 = nums2[mid2];

        if (l1 <= r2 && l2 <= r1)
        {

            return max(l1, l2);
        }

        else if (l1 > r2)
            high = mid1 - 1;

        else
            low = mid1 + 1;
    }

    return 0;
}