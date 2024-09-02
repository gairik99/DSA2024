#include <bits/stdc++.h>
using namespace std;
#define P pair<int, pair<int, int>>

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

int MinimumEffort(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();

    // To store maximum difference
    vector<vector<int>> maxDiff(n, vector<int>(m, 1e9));

    /* Min-Heap storing the pair:
    {diff, {row of cell, column of cell}} */
    priority_queue<P, vector<P>, greater<P>> pq;

    // Mark the initial position as 0
    maxDiff[0][0] = 0;

    // Push the starting cell to min-heap
    pq.push({0, {0, 0}});

    // Until the min-heap is not empty
    while (!pq.empty())
    {

        /* Get the cell with minimum
        difference (effort) */
        auto p = pq.top();

        // Get the difference
        int diff = p.first;

        int row = p.second.first;  // Row
        int col = p.second.second; // Column
        pq.pop();

        /* If the destination cell is reached,
        return the difference */
        if (row == n - 1 && col == m - 1)
            return diff;

        // Traverse it's neighbors
        for (int i = 0; i < 4; i++)
        {

            /* Get the coordinates
            of neighboring cell */
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            // Check if the cell is valid
            if (isValid(newRow, newCol, n, m))
            {

                /* Get the current difference
                in heights of cells */
                int currDiff =
                    abs(heights[newRow][newCol] - heights[row][col]);

                /* Check if the current difference is
                less than earlier known difference */
                if (max(currDiff, diff) < maxDiff[newRow][newCol])
                {

                    // Store the current difference
                    maxDiff[newRow][newCol] = max(currDiff, diff);

                    // Add the new pair found in the min-heap
                    pq.push({max(currDiff, diff), {newRow, newCol}});
                }
            }
        }
    }

    // Return -1
    return -1;
}