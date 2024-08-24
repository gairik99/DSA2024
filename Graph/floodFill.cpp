#include <bits/stdc++.h>
using namespace std;

vector<int> delRow = {-1, 0, 1, 0};
vector<int> delCol = {0, 1, 0, -1};

/* Helper Function to check if a
pixel is within boundaries */
bool isValid(int &i, int &j,
             int &n, int &m)
{

    // Return false if pixel is invalid
    if (i < 0 || i >= n)
        return false;
    if (j < 0 || j >= m)
        return false;

    // Return true if pixel is valid
    return true;
}

// Function to perform DFS traversal
void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int iniColor)
{

    // color with new color
    ans[row][col] = newColor;

    // Getting the dimensions of image
    int n = image.size();
    int m = image[0].size();

    // Traverse the 4 neighbors
    for (int i = 0; i < 4; i++)
    {

        // Coordinates of new pixel
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        /* check for valid, unvisited pixels
        having same initial color */

        if (isValid(nrow, ncol, n, m) &&
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
        {

            // Recirsively perform DFS
            dfs(nrow, ncol, ans, image,
                newColor, iniColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image,
                              int sr, int sc, int newColor)
{

    int iniColor = image[sr][sc];

    // To store the updated image
    vector<vector<int>> ans = image;

    // Start DFS traversal from start cell
    dfs(sr, sc, ans, image, newColor, iniColor);

    // Return the answer image
    return ans;
}