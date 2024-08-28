

void dfs(int node, int vis[], vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto &it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj, st);
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, st);
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> topoSort(int V, vector<int> adj[])
{

    // To store the result
    vector<int> ans;

    // To store the In-degrees of nodes
    vector<int> inDegree(V, 0);

    // Calculating the In-degree of the given graph
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            inDegree[it]++;
    }

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