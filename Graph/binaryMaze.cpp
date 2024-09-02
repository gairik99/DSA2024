#include <bits/stdc++.h>
using namespace std;

vector<int> delRow = {-1, 0, 1, 0};
vector<int> delCol = {0, -1, 0, 1};

// Function to check if a cell is valid
bool isValid(int &row, int &col,
             int &n, int &m)
{

    // Return false if the cell is invalid
    if (row < 0 || row >= n)
        return false;
    if (col < 0 || col >= m)
        return false;

    // Return true if the cell is valid
    return true;
}

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    if (source.first == destination.first && source.second == destination.second)
        return 0;

    /* Queue data structure to store the pairs of the
    form: {dist, {coordinates of cell}} */
    queue<pair<int, pair<int, int>>> q;

    // Dimensions of grid
    int n = grid.size();
    int m = grid[0].size();

    // Distance matrix
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    // Distane of source from itself is zero
    dist[source.first][source.second] = 0;

    // Add the surce to queue
    q.push({0, {source.first, source.second}});

    // Until the queue is empty
    while (!q.empty())
    {
        // Get the element
        auto it = q.front();
        q.pop();

        int dis = it.first;         // Distance
        int row = it.second.first;  // Row of cell
        int col = it.second.second; // Column of cell

        // Iterate through all the neighbors
        for (int i = 0; i < 4; i++)
        {

            // Coordinates of the new cell
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            /* Checking the validity of the cell and
            updating if a shorter distance is found */
            if (isValid(newRow, newCol, n, m) &&
                grid[newRow][newCol] == 1 &&
                dis + 1 < dist[newRow][newCol])
            {

                // Update the distance
                dist[newRow][newCol] = 1 + dis;

                // Return the distance is the destination is reached
                if (newRow == destination.first &&
                    newCol == destination.second)
                    return dis + 1;

                // Add the new cell to queue
                q.push({1 + dis, {newRow, newCol}});
            }
        }
    }

    // If no path is found from source to destination
    return -1;
}