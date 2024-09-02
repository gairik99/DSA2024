#include <bits/stdc++.h>
using namespace std;
#define P pair<int, int>

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Adjacency list to store graph
    vector<pair<int, int>> adj[n + 1];

    // Adding the edges to the graph
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    /* Using priority queue to
    implement Dijkstra Algorithm */
    priority_queue<P, vector<P>, greater<P>> pq;

    // Distance array
    vector<int> dist(n + 1, 1e9);

    // Parent array
    vector<int> parent(n + 1);

    /* Marking each node as
    its own parent initially */
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    /* Distance of source node
    (node 1) to itself is zero */
    dist[1] = 0;

    // Push the source node to the queue.
    pq.push({0, 1});

    // Until the queue is empty
    while (!pq.empty())
    {
        /* Get the pair containing node having
        minimum distance from source node */
        auto it = pq.top();
        pq.pop();

        int node = it.second; // node
        int dis = it.first;   // distance

        // Iterate through the neighbors
        for (auto it : adj[node])
        {

            int adjNode = it.first; // node
            int edWt = it.second;   // edge weight

            /* If the tentative distance to
            reach adjacent node is smaller
            than the known distance */
            if (dis + edWt < dist[adjNode])
            {

                // Update the known distance
                dist[adjNode] = dis + edWt;

                // Push the new pair to priority queue
                pq.push({dis + edWt, adjNode});

                /* Update the parent of the adjNode
                to the recent node(where it came from) */
                parent[adjNode] = node;
            }
        }
    }

    /* If distance to the node could not be found,
    return an array containing -1. */
    if (dist[n] == 1e9)
        return {-1};

    // Array to store the path
    vector<int> path;

    // Start from the destination node
    int node = n;

    /* Iterate backwards from destination
    to source through the parent array */
    while (parent[node] != node)
    {

        // Add the node to the path
        path.push_back(node);

        // Take a step back
        node = parent[node];
    }

    // Add the source node to the path
    path.push_back(1);
    path.push_back(dist[n]);

    /* Since the path stored is in a
    reverse order, reverse the array
    to get the actual path */
    reverse(path.begin(), path.end());

    // Add the path weight in the beginning
    // path.insert(path.begin(), dist[n]);

    // Return the result
    return path;
}