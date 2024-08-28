#include <bits/stdc++.h>
using namespace std;

vector<int> di = {-1, 0, 1, 0};
vector<int> dj = {0, 1, 0, -1};

void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, queue<pair<int, int>> &q)
{
    int n = grid.size(), m = grid[0].size();
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int row = node.first;
        int col = node.second;
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newCol = col + dj[i];
            int newRow = row + di[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol])
                q.push({newRow, newCol});
        }
    }
}

int numberOfEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j])
            {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    bfs(grid, vis, q);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] && !vis[i][j])
                cnt++;
        }
    }

    return cnt;
}