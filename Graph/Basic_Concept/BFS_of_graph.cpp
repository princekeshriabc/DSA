// BFS of graph
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// // time complexity = O(V+E)
// space complexity = O(V)

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V), bfs;
        int node = 0;
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int ele = q.front();
            q.pop();
            bfs.push_back(ele);
            for (auto &neig : adj[ele])
            {
                if (!vis[neig])
                {
                    q.push(neig);
                    vis[neig] = 1;
                }
            }
        }
        return bfs;
    }
};