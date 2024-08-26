// Cycle Detection in Directed Graph
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// time complexity =O(v+E)
// space complexity =O(v)

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        unordered_map<int, int> ind;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                ind[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for (auto it : adj[node])
            {
                ind[it]--;
                if (ind[it] == 0)
                    q.push(it);
            }
        }
        if (count == V)
            return false;
        return true;
    }
};