#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    /* To store the ranks, parents and
    sizes of different set of vertices */
    vector<int> rank, parent, size;

    // Constructor
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Function to find ultimate parent
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Function to implement union by rank
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Function to implement union by size
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> accounts)
    {
        int n = accounts.size(); // Number of accounts

        // Disjoint Set data structure
        DisjointSet ds(n);

        // Hashmap to store the pair: {mails, node}
        unordered_map<string, int> mapMailNode;

        // Iterate on all the accounts
        for (int i = 0; i < n; i++)
        {

            // Iterate on all the mails of the person
            for (int j = 1; j < accounts[i].size(); j++)
            {

                // Get the mail
                string mail = accounts[i][j];

                // If this mail was not already existing
                if (mapMailNode.find(mail) ==
                    mapMailNode.end())
                {

                    // Add it to the hashmap
                    mapMailNode[mail] = i;
                }

                /* Otherwise join it with
                the previous component */
                else
                {

                    // Unite the components
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // To store the merged mails
        vector<string> mergedMail[n];

        // Iterate on the Hashmap
        for (auto it : mapMailNode)
        {

            string mail = it.first;            // Mail
            int node = ds.findUPar(it.second); // Node

            // Add the merged mail to the list
            mergedMail[node].push_back(mail);
        }

        // To return the result
        vector<vector<string>> ans;

        // Iterate on all list of merged mails
        for (int i = 0; i < n; i++)
        {

            /* If a person has no mails,
            skip the iteration */
            if (mergedMail[i].size() == 0)
                continue;

            // Otherwise, add all the merged mails of person
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};