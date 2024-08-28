#include <bits/stdc++.h>
using namespace std;

bool bfs(int node, vector<int> adj[],
         vector<int> &visited)
{

    // Queue to store {node, parent}
    queue<pair<int, int>> q;

    /* Push initial node in queue
    with no one as parent */
    q.push({node, -1});

    // Mark the node as visited
    visited[node] = 1;

    // Until the queue is empty
    while (!q.empty())
    {

        // Get the node and its parent
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // Traverse all the neighbors
        for (auto it : adj[node])
        {

            // If not visited
            if (!visited[it])
            {

                // Mark the node as visited
                visited[it] = 1;

                /* Push the new node in queue
                with curr node as parent */
                q.push({it, node});
            }

            /* Else if it is visited with some
            different parent a cycle is detected */
            else if (it != parent)
                return true;
        }
    }
    return false;
}

bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[node] = true;
    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, node, adj, vis))
                return true;
        }

        else if (parent != it)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            if (bfs(i, adj, vis))
                return true;
    }
    return false;
}