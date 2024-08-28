#include <bits/stdc++.h>
using namespace std;

vector<int> delRow = {-1, 0, 1, 0};
vector<int> delCol = {0, 1, 0, -1};

/* Helper Function to check if a
cell is within boundaries */
bool isValid(int &i, int &j,
             int &n, int &m)
{

    // Return false if cell is invalid
    if (i < 0 || i >= n)
        return false;
    if (j < 0 || j >= m)
        return false;

    // Return true if cell is valid
    return true;
}

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    /* Variable to store time taken
    to get all oranges rotten */
    int time = -1;

    /* Variable to store
    total count of oranges */
    int total = 0;

    /* Variable to store count of
     oranges that are rotten */
    int count = 0;

    // Queue to perform BFS
    queue<pair<int, int>> q;

    // Traverse the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            /* If cell contains orange,
            increment total */
            if (grid[i][j] != 0)
                total++;

            /* If cell contains rotten
             orange, push in queue */
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    // Perform BFS

    // Until the queue is empty
    while (!q.empty())
    {

        // Get the size of queue
        time++;
        int k = q.size();

        // Update count of rotten oranges
        count += k;

        // Perform BFS for current level
        while (k--)
        {

            // Get the cell from queue
            auto cell = q.front();
            q.pop();

            // Get its coordinates
            int row = cell.first;
            int col = cell.second;

            // Traverse its 4 neighbors
            for (int i = 0; i < 4; i++)
            {

                // Coordinates of new cell
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                /* check for valid, unvisited
                 cells having fresh oranges */
                if (isValid(nRow, nCol, n, m) &&
                    grid[nRow][nCol] == 1)
                {

                    /* Mark the new orange as rotten
                    and add it to the queue */
                    grid[nRow][nCol] = 2;
                    q.push({nRow, nCol});
                }
            }
        }

        /* If new oranges are rotten, then
         the time must be incremented */
    }

    /* If all the oranges are rotten,
    return the time taken */
    if (total == count)
        return max(time, 0);

    // Otherwise return -1
    return -1;
}