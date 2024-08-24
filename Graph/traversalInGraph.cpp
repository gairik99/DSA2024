#include <bits/stdc++.h>
using namespace std;

void bfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        vis[node] = 1;
        ans.push_back(node);
        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto &it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis, ans);
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, ans);
        }
    }
    return ans;
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            bfs(i, adj, vis, ans);
        }
    }
    return ans;
}
