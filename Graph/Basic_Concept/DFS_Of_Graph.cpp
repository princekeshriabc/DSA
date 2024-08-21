// DFS Of Graph
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// time complexity = O(V+E)
// space complexity = O(V)

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfstra(vector<int> &vis, int V, vector<int> &dfs, int node, vector<int> adj[])
    {
        dfs.push_back(node);
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfstra(vis, V, dfs, it, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here

        vector<int> vis(V), dfs;

        dfstra(vis, V, dfs, 0, adj);
        return dfs;
    }
};