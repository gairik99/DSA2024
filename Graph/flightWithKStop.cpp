#include <bits/stdc++.h>
using namespace std;
#define P pair<int, pair<int, int>>

int CheapestFlight(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    // Adding edges to the graph
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    // To store minimum distance
    vector<int> minDist(n, 1e9);

    /* Queue storing the elements of
    the form {stops, {node, dist}} */
    priority_queue<P, vector<P>, greater<P>> q;

    // Add the source to the queue
    q.push({0, {src, 0}});

    // Until the queue is empty
    while (!q.empty())
    {

        // Get the element from queue
        auto p = q.top();
        q.pop();

        int stops = p.first;        // stops
        int node = p.second.first;  // node
        int dist = p.second.second; // distance

        /* If the number of stops taken exceed k,
        skip and move to the next element */
        if (stops > k)
            continue;

        // Traverse all the neighbors
        for (auto it : adj[node])
        {

            int adjNode = it.first; // Adjacent node
            int edgeWt = it.second; // Edge weight

            /* If the tentative distance to
            reach adjacent node is smaller
            than the known distance and number
            of stops doesn't exceed k */
            if (dist + edgeWt < minDist[adjNode] &&
                stops <= k)
            {

                // Update the known distance
                minDist[adjNode] = dist + edgeWt;

                // Add the new element to queue
                q.push({stops + 1, {adjNode, dist + edgeWt}});
            }
        }
    }

    /* If the destination is
    unreachable, return -1 */
    if (minDist[dst] == 1e9)
        return -1;

    // Otherwise return the result
    return minDist[dst];
}