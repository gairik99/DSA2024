#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<int> adj[], int color[])
{
    // Queue for BFS traversal
    queue<int> q;

    // Add initial node to queue
    q.push(start);
    color[start] = 0; // Mark it with a color

    // While queue is not empty
    while (!q.empty())
    {
        // Get the node
        int node = q.front();
        q.pop();

        // Traverse all its neighbors
        for (auto it : adj[node])
        {

            // If not already colored
            if (color[it] == -1)
            {

                // Color it with opposite color.
                color[it] = !color[node];

                // Push the node in queue
                q.push(it);
            }

            // Else if the neighbor has same color as node
            else if (color[it] == color[node])
            {

                /* Return false, as the
                component is not bipartite */
                return false;
            }
        }
    }

    // Return true is the component is bipartite
    return true;
}

bool dfs(int node, int col, vector<int> adj[], int color[])
{

    // Color the current node
    color[node] = col;

    // Traverse adjacent nodes
    for (auto it : adj[node])
    {

        // if uncoloured
        if (color[it] == -1)
        {

            // Recursively color the nodes
            if (dfs(it, !col, adj, color) == false)
                return false;
        }

        // if previously coloured and have the same colour
        else if (color[it] == col)
        {

            // Return false as it is not bipartite
            return false;
        }
    }

    /* Return true if all the nodes can
    be colored with alternate colors */
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = -1;

    // Traverse all the nodes
    for (int i = 0; i < V; i++)
    {

        // If not colored, start the traversal
        if (color[i] == -1)
        {
            // Return false if graph is not bipartite
            if (!dfs(i, 1, adj, color))
                return false;
        }
    }

    /* Return true if each
    component is bipartite */
    return true;
}