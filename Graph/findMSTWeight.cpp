#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> vis(V, 0);
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        auto tp = pq.top();
        pq.pop();
        int wt = tp.first;
        int node = tp.second;
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        sum += wt;
        for (auto &it : adj[node])
        {
            int weight = it[1];
            int adjNode = it[0];
            if (!vis[adjNode])
                pq.push({weight, adjNode});
        }
    }
    return sum;
}