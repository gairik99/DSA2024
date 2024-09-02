#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<int> adj[],
         vector<int> &dist)
{

    // Distance of source node from itself is zero
    dist[src] = 0;

    // Queue to facilitate BFS traversal
    queue<int> q;

    // Adding source node to queue
    q.push(src);

    // Until the queue is empty
    while (!q.empty())
    {

        // Get the node from queue
        int node = q.front();
        q.pop();

        // Traverse all its neighbors
        for (auto adjNode : adj[node])
        {

            // If a shorter distance is found
            if (dist[node] + 1 < dist[adjNode])
            {

                // Update the distance
                dist[adjNode] = 1 + dist[node];

                // Add the node to the queue
                q.push(adjNode);
            }
        }
    }
}

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M)
{
    vector<int> adj[N];

    // Add edges to the graph
    for (auto it : edges)
    {
        int u = it[0]; // first node
        int v = it[1]; // second node

        // Add the edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Distance array to store the shortest paths
    vector<int> dist(N, 1e9);

    // Start the BFS traversal from source node
    bfs(0, adj, dist);

    /* If a node is unreachable,
    updating its distance to -1 */
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }

    // Return the result
    return dist;
}