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
    int solve(int n, vector<vector<int>> &Edge)
    {

        int size = Edge.size();

        /* Return -1 if connecting all
        vertices is not possible */
        // if(size < n-1) return -1;

        // Disjoint Set data structure
        DisjointSet ds(n);
        int extra = 0;
        // Add all the edges in the set
        for (int i = 0; i < size; i++)
        {
            if (ds.findUPar(Edge[i][0]) == ds.findUPar(Edge[i][1]))
                extra++;
            else
                ds.unionByRank(Edge[i][0], Edge[i][1]);
        }

        // To store count of required edges
        int count = 0;

        // Finding the number of components
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                count++;
        }

        // Return the result
        if (count - 1 <= extra)
            return count - 1;
        return -1;
    }
};