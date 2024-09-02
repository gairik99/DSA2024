#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    /* To store the ranks, parents and
    sizes of different set of vertices */
    vector<int> parent, size;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int uPar = findUPar(u);
        int vPar = findUPar(v);
        if (uPar == vPar)
            return;
        if (size[uPar] >= size[vPar])
        {
            parent[vPar] = uPar;
            size[uPar] += size[vPar];
        }
        else
        {
            parent[uPar] = vPar;
            size[vPar] += uPar;
        }
    }
};

class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        DisjointSet ds(V);

        // Adding the edges to the disjoint set
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {

                // If node i and node j are connected
                if (adj[i][j] == 1)
                {

                    // Joining them in disjoint set
                    ds.unionBySize(i, j);
                }
            }
        }

        // To store the number of provinces
        int count = 0;

        // Check for all the nodes
        for (int i = 0; i < V; i++)
        {

            /* Increment the count if a unique
            ultimate parent node is found */
            if (ds.parent[i] == i)
                count++;
        }

        // Return the result
        return count;
    }
};