#include <bits/stdc++.h>
using namespace std;
#define P pair<int, int>

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> dis(V, 1e9);
    dis[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        for (auto &it : adj[node])
        {
            if (dist + it[1] < dis[it[0]])
            {
                dis[it[0]] = dist + it[1];
                pq.push({dis[it[0]], it[0]});
            }
        }
    }
    return dis;
}