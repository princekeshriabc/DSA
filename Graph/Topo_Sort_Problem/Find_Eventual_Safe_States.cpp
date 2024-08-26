// Find Eventual Safe States
// https://leetcode.com/problems/find-eventual-safe-states/solutions/5692221/simple-solution-using-bfs-striver-approach/
// time complexity =O(v+E)
// space complexity =O(v)

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> adjr[n];
        vector<int> ind(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
            {
                adjr[it].push_back(i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (auto it : adjr[i])
            {
                ind[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        vector<int> res;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto it : adjr[node])
            {
                ind[it]--;
                if (ind[it] == 0)
                    q.push(it);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};