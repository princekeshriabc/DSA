// Critical Connections in a Network
// https://leetcode.com/problems/critical-connections-in-a-network/solutions/5744704/simple-solution-using-dfs-striver-approach/

// Time complexity : O(E + v) + (3n)
// Space complexity : O(n∗E)

class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<vector<int>> &bridges, vector<int> &low, vector<int> &tin)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (vis[it] == 0)
            {
                dfs(it, node, vis, adj, bridges, low, tin);
                low[node] = min(low[node], low[it]);
                if (tin[node] < low[it])
                    bridges.push_back({it, node});
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> bridges;
        vector<int> adj[n];
        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0), tin(n), low(n);
        dfs(0, -1, vis, adj, bridges, low, tin);
        return bridges;
    }
};