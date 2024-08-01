#include <bits/stdc++.h>
using namespace std;
// problem link
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

int numberOfSubstrings(string s)
{
    // std::unordered_map<char, int> lastSeen = {
    //     {'a', -1}, {'b', -1}, {'c', -1}};
    int lastSeen[3] = {-1, -1, -1};
    // Variable to keep track of the total count of valid substrings
    int count = 0;

    // Iterate through each character in the string
    for (int i = 0; i < s.length(); ++i)
    {
        // Update the last seen index for the current character
        lastSeen[s[i] - 'a'] = i;

        // Calculate the number of valid substrings ending at the current
        // position
        // 1. Find the leftmost index among 'a', 'b', and 'c'
        // 2. All substrings from this leftmost index to the current
        // position are valid
        // 3. Add 1 to include the substring starting at the current
        // position itself
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
            count += 1 + std::min({lastSeen[0], lastSeen[1], lastSeen[2]});
    }

    // Return the total count of valid substrings
    return count;
}