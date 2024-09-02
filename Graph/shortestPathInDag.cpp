#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto &it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
            dfs(v, adj, vis, st);
    }
    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[N];
    for (auto &it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    stack<int> st;
    vector<int> vis(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
            dfs(i, adj, vis, st);
    }
    vector<int> dist(N, 1e9);
    dist[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        for (auto &it : adj[node])
        {
            if (dist[node] + it.second < dist[it.first])
                dist[it.first] = dist[node] + it.second;
        }
    }
    // for(auto &it:dist)
    //    if(it==1e9)it=-1;
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }

    return dist;
}