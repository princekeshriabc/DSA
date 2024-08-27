// Shortest Path in UG with unit weights
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance
// time complexity =O(v+E)
// space complexity =O(v)

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // code here
        vector<int> adj[N];
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(N, 1e9);
        queue<pair<int, int>> q;
        q.push({src, 0});
        dist[src] = 0;
        while (!q.empty())
        {
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            for (auto it : adj[node])
            {
                if (dist[it] > dis + 1)
                {
                    dist[it] = dis + 1;
                    q.push({it, dis + 1});
                }
            }
        }
        vector<int> res(N, -1);
        for (int i = 0; i < N; i++)
        {
            if (dist[i] != 1e9)
            {
                res[i] = dist[i];
            }
        }
        return res;
    }
};