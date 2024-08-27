// Dijkstra Algorithm
// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
// time complexity =O(E log V)
// space complexity =O(V)

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj1[], int S)
    {
        // Code here
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj1[i])
            {
                adj[i].push_back({it[0], it[1]});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        pq.push({0, S});
        dist[S] = 0;
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int nod = it.first;
                int wt = it.second;
                if (wt + dist[node] < dist[nod])
                {
                    dist[nod] = wt + dist[node];
                    pq.push({dist[nod], nod});
                }
            }
        }
        return dist;
    }
};
