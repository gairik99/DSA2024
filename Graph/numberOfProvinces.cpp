#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjL[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto &it : adjL[node])
        if (vis[it] == 0)
            dfs(it, adjL, vis);
}

void bfs(int node, vector<int> adjL[], vector<int> &vis)
{
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        vis[node] = 1;
        for (auto &it : adjL[node])
        {
            if (!vis[it])
                q.push(it);
        }
    }
    return;
}

int numProvinces(vector<vector<int>> adj)
{
    int V = adj.size();
    vector<int> adjL[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] != 0 && i != j)
            {
                adjL[i].push_back(j);
                adjL[j].push_back(i);
            }
        }
    }
    vector<int> vis(V, 0);
    int cnt = 0;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            cnt++;
            bfs(i, adjL, vis);
        }
    }
    return cnt;
}