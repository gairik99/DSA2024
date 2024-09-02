#include <bits/stdc++.h>
using namespace std;
#define P pair<long long, int>

int countPaths(int n, vector<vector<int>> &roads)
{
    int mod = 1e9 + 7;

    // To store the graph
    vector<pair<int, int>> adj[n];

    // Adding the edges to the graph
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    /* Array to store the minimum
    time to get to nodes */
    vector<long long> minTime(n, LLONG_MAX);

    /* To store the number of
    ways to reach nodes */
    vector<int> ways(n, 0);

    // Priority queue to store: {time, node}
    priority_queue<P, vector<P>, greater<P>> pq;

    // Initial configuration
    minTime[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    // Until the priority queue is empty
    while (!pq.empty())
    {

        // Get the element
        auto p = pq.top();
        pq.pop();

        long long time = p.first; // time
        int node = p.second;      // node

        // Traverse its neighbors
        for (auto it : adj[node])
        {

            int adjNode = it.first;     // adjacent node
            int travelTime = it.second; // travel time

            /* If the current time taken is less than
            earlier known time to reach adjacent node */
            if (minTime[adjNode] > time + travelTime)
            {

                // Update the time to reach adjacent node
                minTime[adjNode] = time + travelTime;

                // Update the number of ways
                ways[adjNode] = ways[node];

                // Add the new element in priority queue
                pq.push({minTime[adjNode], adjNode});
            }

            /* Else if the current time taken is same as
            earlier known time to reach adjacent node */
            else if (minTime[adjNode] == time + travelTime)
            {

                /* Update the number of ways
                to reach adjacent nodes */
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    // Return the result
    return ways[n - 1] % mod;
}