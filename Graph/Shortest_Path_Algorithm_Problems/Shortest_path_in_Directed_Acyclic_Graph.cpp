// Shortest path in Directed Acyclic Graph
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph

class Solution
{
private:
    void dfs(int node, stack<int> &st, vector<int> &vis, vector<pair<int, int>> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                dfs(it.first, st, vis, adj);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        vector<pair<int, int>> adj[N];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                dfs(i, st, vis, adj);
            }
        }
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node])
            {
                if ((it.second + dist[node]) < dist[it.first])
                {
                    dist[it.first] = it.second + dist[node];
                }
            }
        }
        vector<int> ans(N, -1);
        for (int it = 0; it < N; it++)
        {
            if (dist[it] != 1e9)
            {
                ans[it] = dist[it];
            }
        }
        return ans;
    }
};