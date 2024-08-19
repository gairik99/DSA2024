#include <bits/stdc++.h>
using namespace std;

bool func(vector<vector<char>> &v, int i, int j, string &s, int k)
{
    // If all characters of the word are found
    if (k == s.length())
    {
        return true;
    }
    // Boundary conditions and character mismatch check
    if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || s[k] != v[i][j])
    {
        return false;
    }

    // Initialize answer as false
    bool ans = false;

    // Temporarily mark the cell as visited
    char x = v[i][j];
    v[i][j] = ' ';

    // Check all four possible directions (down, up, right, left)
    ans |= func(v, i + 1, j, s, k + 1);
    ans |= func(v, i - 1, j, s, k + 1);
    ans |= func(v, i, j + 1, s, k + 1);
    ans |= func(v, i, j - 1, s, k + 1);

    // Restore the original character in the cell
    v[i][j] = x;

    return ans;
}
bool exist(vector<vector<char>> &board, string word)
{
    // your code goes here
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            // If the first character matches, start the search
            if (board[i][j] == word[0])
            {
                // If the word is found, return true
                if (func(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }
    }
    // If the word is not found, return false
    return false;
}