// Prim's Algorithm
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Time complexity = O(E log (E))
// Space complexity = O(V)  // max (E,V)

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> vis(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            int node = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            if (vis[node] == 1)
                continue;
            vis[node] = 1;
            sum += w;
            for (auto it : adj[node])
            {
                int eg = it[0];
                int egw = it[1];
                if (!vis[eg])
                {
                    pq.push({egw, eg});
                }
            }
        }
        return sum;
    }
};