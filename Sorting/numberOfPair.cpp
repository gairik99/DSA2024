#include <bits/stdc++.h>
using namespace std;

int DFS(int i, vector<vector<int>> &graph, vector<int> &visited)
{
    visited[i] = 1;
    int cnt = 1;
    for (int nbr : graph[i])
    {
        if (visited[nbr] == 0)
        {
            cnt += DFS(nbr, graph, visited);
        }
    }
    return cnt;
}

long long int numberOfPairs(vector<vector<int>> &pairs, int p, int n)
{
    // code here
    vector<vector<int>> graph(n);
    for (int i = 0; i < p; i++)
    {
        int u = pairs[i][0], v = pairs[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n, 0);

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            int cnt = DFS(i, graph, visited);
            ans += (long long)(n - cnt) * cnt;
        }
    }

    return ans / 2;
}