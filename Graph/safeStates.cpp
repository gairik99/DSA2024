#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis,
              vector<int> &check)
{

    // Mark the node as visited
    vis[node] = 1;

    // Add the node to current path
    pathVis[node] = 1;

    // Mark the node as potentially unsafe
    // check[node] = 0;

    // Traverse for adjacent nodes
    for (auto it : adj[node])
    {

        // When the node is not visited
        if (!vis[it])
        {

            /* Perform DFS recursively and if
            a cycle is found, return false */
            if (dfsCheck(it, adj, vis, pathVis, check))
            {

                /* Return true since a
                cycle was detected */
                return true;
            }
        }

        /* Else if the node has been previously
        visited in the same path*/
        else if (pathVis[it])
        {

            /* Return true since a
            cycle was detected */
            return true;
        }
    }

    /* If the current node neither exist
    in a cycle nor points to a cycle,
    it can be marked as a safe node */
    check[node] = 1;

    // Remove the node from the current path
    pathVis[node] = 0;

    // Return false since no cycle was found
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<int> vis(V, false);

    // Path Visited array
    vector<int> pathVis(V, false);

    // To keep a check of safe nodes
    vector<int> check(V, false);

    /* Traverse the graph and
    check for safe nodes */
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {

            // Start DFS traversal
            dfsCheck(i, adj, vis, pathVis, check);
        }
    }

    // To store the result
    vector<int> ans;

    // Add the safe nodes to the result
    for (int i = 0; i < V; i++)
    {
        if (check[i] == 1)
            ans.push_back(i);
    }

    // Return the result
    return ans;
}