#include <bits/stdc++.h>
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> adjMat(n, vector<int>(n, 1e9));

    // Filling up the adjacency matrix
    for (auto it : edges)
    {
        adjMat[it[0]][it[1]] = it[2];
        adjMat[it[1]][it[0]] = it[2];
    }

    // Applying Floyd Warshall Algorithm

    // For intermediate node k
    for (int k = 0; k < n; k++)
    {

        // node i ---> node j
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adjMat[i][j] =
                    min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
            }
        }
    }

    // To store the minimum count of neighbors
    int minCount = 1e9;

    /* To store the answer (city having
    smallest number of neighbors) */
    int ans;

    // Check every city
    for (int i = 0; i < n; i++)
    {

        /* To count the neighbors of given city
        having distance lesser than threshold */
        int count = 0;

        // City i ---> City j
        for (int j = 0; j < n; j++)
        {

            /* If the distance to reach city j from
            city i is less than threshold */
            if (i != j && adjMat[i][j] <= distanceThreshold)
            {

                // Increment count
                count++;
            }
        }

        // if current count is less than minimum count
        if (count < minCount)
        {

            // Update minimum count
            minCount = count;

            // Store the answer
            ans = i;
        }

        /* Else if current count is
        equal to minimum count */
        else if (count == minCount)
        {

            /* Update the answer (to store
            city with greater number) */
            ans = i;
        }
    }

    // Return the resulting city as answer
    return ans;
}