// Cycle Detection in unirected Graph
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
// time complexity = O(V+E)
// space complexity = O(V) 

// this code solved by dfs
class Solution
{
private:
    bool detectdfs(int src, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[src] = 1;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                if (detectdfs(it, src, vis, adj))
                    return true;
            }
            else if (parent != it)
                return true;
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detectdfs(i, -1, vis, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// this code solved by bfs
bool detect(int src,vector<int>& vis,vector<int> adj[]){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }
            else if(parent!=it){
                return true;
            }
        }
    }
    return false;
}