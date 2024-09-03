#include <bits/stdc++.h>
using namespace std;

int timer = 1;

/* Helper function to make DFS calls while
identifying articulation points */
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin,
         vector<int> &low, vector<int> &mark, vector<int> adj[])
{

    // Mark the node as visited
    vis[node] = 1;

    /* Time of insertion and the lowest time of
    insert for node will be the current time */
    tin[node] = low[node] = timer;

    // Increment the timer
    timer++;

    // To count the number of children of the node
    int child = 0;

    // Traverse all its neighbor
    for (auto it : adj[node])
    {

        // Skip the parent
        if (it == parent)
            continue;

        // If a neighbor is not visited
        if (!vis[it])
        {

            // Make a recursive DFS call
            dfs(it, node, vis, tin, low, mark, adj);

            /* Once the recursive DFS call returns, upate
            the lowest time of insertion for the node */
            low[node] = min(low[node], low[it]);

            /* If the lowest time of insertion of the node is
            found to be greater than the time of insertion
            of the neighbor and it is node the starting node */
            if (low[it] >= tin[node] && parent != -1)
            {

                // Mark the node as an articulation point
                mark[node] = 1;
            }

            // Increment the child counter
            child++;
        }

        // Else if the neighbor is already visited
        else
        {

            // Update the lowest time of insertion of the node
            low[node] = min(low[node], tin[it]);
        }
    }

    /* If the node is not a starting node
    and has more than one child */
    if (child > 1 && parent == -1)
    {

        // Mark the node as an articulation point
        mark[node] = 1;
    }
}

vector<int> articulationPoints(int n, vector<int> adj[])
{

    vector<int> vis(n, 0);

    // To store the time of insertion(discovery time) of nodes
    vector<int> tin(n);

    // To store the lowest time of insert of the nodes
    vector<int> low(n);

    // To mark if a node is an articulation point
    vector<int> mark(n, 0);

    // Start DFS traversal of the graph
    for (int i = 0; i < n; i++)
    {

        // If a node is not visited
        if (!vis[i])
        {

            //  Perform DFS starting from that node
            dfs(i, -1, vis, tin, low, mark, adj);
        }
    }

    // To store the nodes that are articulation point
    vector<int> ans;

    // Traverse all nodes
    for (int i = 0; i < n; i++)
    {

        // If the node is marked as an articulation point
        if (mark[i] == 1)
        {
            // Add it to the result
            ans.push_back(i);
        }
    }

    // If there are no articulation points, return -1
    if (ans.size() == 0)
        return {-1};

    // Return the result
    return ans;
}