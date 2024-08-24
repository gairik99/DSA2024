#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjLs[], int vis[])
{

    // Mark the node as visited
    vis[node] = 1;

    // Traverse its unvisited neighbours
    for (auto it : adjLs[node])
    {

        if (!vis[it])
        {
            // Recursively perform DFS
            dfs(it, adjLs, vis);
        }
    }
}

int findNumberOfComponent(int E, int V, vector<vector<int>> &edges)
{
    vector<int> adjLs[V];

    // Add edges to adjacency list
    for (int i = 0; i < E; i++)
    {
        adjLs[edges[i][0]].push_back(edges[i][1]);
        adjLs[edges[i][1]].push_back(edges[i][0]);
    }

    // Visited array
    int vis[V] = {0};

    // Variable to store number of components
    int cnt = 0;

    // Start Traversal
    for (int i = 0; i < V; i++)
    {
        // If the node is not visited
        if (!vis[i])
        {
            // Increment counter
            cnt++;

            /* Start traversal from current
            node using any traversal */
            dfs(i, adjLs, vis);
            // dfs(i, adjLs, vis);
        }
    }

    // Return the count
    return cnt;
}