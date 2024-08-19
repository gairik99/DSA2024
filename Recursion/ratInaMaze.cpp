#include <bits/stdc++.h>
using namespace std;

vector<string> result;
void path(vector<vector<int>> &m, int x, int y, string dir, int n)
{
    // If destination is reached, add path to result
    if (x == n - 1 && y == n - 1)
    {
        result.push_back(dir);
        return;
    }

    // If cell is blocked, return
    if (m[x][y] == 0)
        return;

    // Mark cell as visited by setting it to 0
    m[x][y] = 0;

    // Move up if possible
    if (x > 0)
        path(m, x - 1, y, dir + 'U', n);
    // Move left if possible
    if (y > 0)
        path(m, x, y - 1, dir + 'L', n);
    // Move down if possible
    if (x < n - 1)
        path(m, x + 1, y, dir + 'D', n);
    // Move right if possible
    if (y < n - 1)
        path(m, x, y + 1, dir + 'R', n);

    // Unmark cell as visited by setting it to 1
    m[x][y] = 1;
}
vector<string> findPath(vector<vector<int>> &grid)
{
    // your code goes here
    int n = grid.size();

    // Clear previous results
    result.clear();

    // If starting or ending cell is blocked, return empty result
    if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0)
        return result;

    // Start finding paths from (0, 0)
    path(grid, 0, 0, "", n);

    // Sort the result paths
    sort(result.begin(), result.end());

    return result;
}