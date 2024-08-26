// Topological sort
// https://www.geeksforgeeks.org/problems/topological-sort/1
// time complexity =O(v+E)
// space complexity =O(v)

// using dfs
class Solution
{
    private:
    void dfs(int node,vector<int>& vis,vector<int> adj[],stack<int>& st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
	    // code here
	    vector<int> vis(V,0);
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,adj,st);
	        }
	    }
	    vector<int> res;
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
};

// using bfs
class Solution
{
private:
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> ind;
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
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                ind[it]--;
                if (ind[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
};