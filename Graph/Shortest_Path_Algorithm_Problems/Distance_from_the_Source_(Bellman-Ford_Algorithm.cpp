// Distance from the Source (Bellman-Ford Algorithm)
// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    // Code here
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && wt + dist[u] < dist[v])
            {
                dist[v] = wt + dist[u];
            }
        }
    }
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && wt + dist[u] < dist[v])
        {
            return {-1};
        }
    }
    return dist;
}
};