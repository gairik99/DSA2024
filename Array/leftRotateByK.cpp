#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int> &a, int d)
{
    d %= a.size();
    // First reversing d elements from starting index.
    reverse(a.begin(), a.begin() + d);
    // Then reversing the last n-d elements.
    reverse(a.begin() + d, a.end());
    // Finally, reversing the whole array.
    reverse(a.begin(), a.end());
}