#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, size, rank;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool find(int u, int v)
    {
        return findUPar(u) == findUPar(v);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // Return if nodes already belong to the same component
        if (ulp_u == ulp_v)
            return;

        /* Otherwise, join the node to the other
        node having higher ranks among the two */
        if (rank[ulp_u] < rank[ulp_v])
        {
            // Update the parent
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            // Update the parent
            parent[ulp_v] = ulp_u;
        }

        /* If both have same rank, join any node to the
        other and increment the rank of the parent node */
        else
        {
            // Update the parent
            parent[ulp_v] = ulp_u;

            // Update the rank
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int uPar = findUPar(u);
        int vPar = findUPar(v);
        if (uPar == vPar)
            return;
        if (size[u] >= size[v])
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