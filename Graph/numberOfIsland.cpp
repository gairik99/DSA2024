#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    if (row < 0 || col < 0 || row >= n || col >= m || vis[row][col] == 1 || grid[row][col] == '0')
        return;
    vis[row][col] = 1;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int newRow = row + di;
            int newCol = col + dj;
            dfs(newRow, newCol, n, m, vis, grid);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                cnt++;
                dfs(i, j, n, m, vis, grid);
            }
        }
    }
    return cnt;
}