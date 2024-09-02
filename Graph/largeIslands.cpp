#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    /* To store the ranks, parents and
    sizes of different set of vertices */
    vector<int> rank, parent, size;

    // Constructor
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Function to find ultimate parent
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Function to implement union by rank
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Function to implement union by size
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    /* Helper Function to check if a
    pixel is within boundaries */
    bool isValid(int &i, int &j, int &n)
    {

        // Return false if pixel is invalid
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= n)
            return false;

        // Return true if pixel is valid
        return true;
    }

    void addInitialIslands(vector<vector<int>> grid,
                           DisjointSet &ds, int n)
    {

        // Traverse all the cells in the grid
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {

                // If the cell is not land, skip
                if (grid[row][col] == 0)
                    continue;

                // Traverse on all the neighbors
                for (int ind = 0; ind < 4; ind++)
                {

                    // Get the coordinates of neighbor
                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];

                    // If the cell is valid and a land cell
                    if (isValid(newRow, newCol, n) &&
                        grid[newRow][newCol] == 1)
                    {

                        // Get the number for node
                        int nodeNo = row * n + col;
                        // Get the number for neighbor
                        int adjNodeNo = newRow * n + newCol;

                        /* Take union of both nodes as they
                        are part of the same island */
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // Disjoint Set data structure
        DisjointSet ds(n * n);

        /* Function call to add initial
        islands in the disjoint set */
        addInitialIslands(grid, ds, n);

        // To store the answer
        int ans = 0;

        // Traverse on the grid
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {

                // If the cell is a land cell, skip
                if (grid[row][col] == 1)
                    continue;

                /* Set to store the ultimate parents
                of neighboring islands */
                set<int> components;

                // Traverse on all its neighbors
                for (int ind = 0; ind < 4; ind++)
                {

                    // Coodinates of neigboring cell
                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];

                    if (isValid(newRow, newCol, n) &&
                        grid[newRow][newCol] == 1)
                    {

                        /* Perform union and store
                        ultimate parent in the set */
                        int nodeNumber = newRow * n + newCol;
                        components.insert(ds.findUPar(nodeNumber));
                    }
                }

                // To store the size of current largest island
                int sizeTotal = 0;

                // Iterate on all the neighborinh ultimate parents
                for (auto it : components)
                {

                    // Update the size
                    sizeTotal += ds.size[it];
                }

                // Store the maximum size of island
                ans = max(ans, sizeTotal + 1);
            }
        }

        // Edge case
        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {

            // Keep the answer updated
            ans = max(ans, ds.size[ds.findUPar(cellNo)]);
        }

        // Return the answer
        return ans;
    }
};
