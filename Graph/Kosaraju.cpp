#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{

    // Mark the node as visited
    vis[node] = 1;

    // Traverse all its neighbors
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            // Recursively perform DFS is not visited already
            dfs(it, vis, adj, st);
        }
    }

    // Push the node in stack
    st.push(node);
}

/* Helper function to perform DFS for finding
number of Strongly connected components */
void helperDFS(int node, vector<int> &vis,
               vector<int> adjT[])
{

    // Mark the node as visited
    vis[node] = 1;

    // Traverse all its neighbors
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            // Recursively perform DFS if not already visited
            helperDFS(it, vis, adjT);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);

    // Stack data structure
    stack<int> st;

    /* Perform initial DFS to store the nodes
    in stack based on their finishing time */
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    // To store the revered graph
    vector<int> adjT[V];

    /* Reverse all the edges of original
    graph to the reversed graph */
    for (int i = 0; i < V; i++)
    {

        // Mark the node as unvisited
        vis[i] = 0;

        // Add the reversed edge
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    /* To store the count of strongly
    connected components */
    int count = 0;

    /* Start DFS call from every unvisited
    node based on their finishing time */
    while (!st.empty())
    {
        // Get the node
        int node = st.top();
        st.pop();

        // If not visited already
        if (!vis[node])
        {
            count += 1;
            helperDFS(node, vis, adjT);
        }
    }

    // Return the result
    return count;
}