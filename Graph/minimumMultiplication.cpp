#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // Base case
    if (start == end)
        return 0;

    // Size of array
    int n = arr.size();
    int mod = 100000; // mod

    /* Array to store minimum
    steps (distance array) */
    vector<int> minSteps(1e5, INT_MAX);

    /* Queue to implement
    Dijkstra's algorithm */
    queue<P> q;

    // Mark initial position as 0
    minSteps[start] = 0;

    // Add the initial node to queue
    q.push({0, start});

    // Until the queue is empty
    while (!q.empty())
    {

        // Get the element
        auto p = q.front();
        q.pop();

        int steps = p.first; // steps
        int val = p.second;  // value

        // Check for adjacent neighbors
        for (int i = 0; i < n; i++)
        {

            // Value of neighboring node
            int num = (val * arr[i]) % mod;

            // If end is reached, return steps taken
            if (num == end)
                return steps + 1;

            /* Check if the current steps taken is
            less than earlier known steps */
            if (steps + 1 < minSteps[num])
            {

                // Update the known steps
                minSteps[num] = steps + 1;

                // Insert the pair in queue
                q.push({steps + 1, num});
            }
        }
    }

    /* Return -1 if reaching
    end is not possible */
    return -1;
}