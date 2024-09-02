#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{

    // To store the In-degrees of nodes
    vector<int> inDegree(V, 0);

    // Update the in-degrees of nodes
    for (int i = 0; i < V; i++)
    {

        for (auto it : adj[i])
        {
            // Update the in-degree
            inDegree[it]++;
        }
    }

    // To store the result
    vector<int> ans;

    // Queue to facilitate BFS
    queue<int> q;

    // Add the nodes with no in-degree to queue
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    // Until the queue is empty
    while (!q.empty())
    {

        // Get the node
        int node = q.front();

        // Add it to the answer
        ans.push_back(node);
        q.pop();

        // Traverse the neighbours
        for (auto it : adj[node])
        {

            // Decrement the in-degree
            inDegree[it]--;

            /* Add the node to queue if
            its in-degree becomes zero */
            if (inDegree[it] == 0)
                q.push(it);
        }
    }

    // Return the result
    return ans;
}

string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];

    // Compare the consecutive words
    for (int i = 0; i < N - 1; i++)
    {

        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());

        /* Compare the pair of strings letter by
        letter to identify the differentiating letter */
        for (int ptr = 0; ptr < len; ptr++)
        {

            // If the differentiating letter is found
            if (s1[ptr] != s2[ptr])
            {

                // Add the edge to the graph
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    /* Get the topological sort
    of the graph formed */
    vector<int> topo = topoSort(K, adj);

    // To store the answer
    string ans;

    for (int i = 0; i < K; i++)
    {
        // Add the letter to the result
        ans.push_back('a' + topo[i]);
        ans.push_back(' ');
    }

    // Return the answer
    return ans;
}