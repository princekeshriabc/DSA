// Print adjacency list
// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-adjacency-list
// // time complexity = O(E)
// space complexity = O(E*v)

class Solution
{
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
    {
        // Code here
        int m = edges.size();
        vector<vector<int>> adj(V);
        for (int i = 0; i < m; i++)
        {
            int x = edges[i].first;
            int y = edges[i].second;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        return adj;
    }
};