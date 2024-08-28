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

// Recursive function to perform DFS
void dfs(int row, int col,
         vector<vector<bool>> &vis,
         vector<vector<char>> &mat,
         int &n, int &m)
{

    // Mark the node as visited
    vis[row][col] = true;

    // Check the 4 neighbors
    for (int i = 0; i < 4; i++)
    {

        // Determine coordinates of new cell
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        /* If an unvisited, valid
        cell contains 'O' */
        if (isValid(nRow, nCol, n, m) &&
            mat[nRow][nCol] == 'O' &&
            !vis[nRow][nCol])
        {

            // Recursive DFS traversal
            dfs(nRow, nCol, vis, mat, n, m);
        }
    }
}