// Number of provinces
// https://leetcode.com/problems/number-of-provinces/solutions/5667677/simple-solution-in-c/
// time complexity = O(V+E)
// space complexity = O(V)

class Solution
{
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, vis, adj);
            }
        }
        return count;
    }
};