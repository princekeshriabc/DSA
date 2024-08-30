// Network Delay time
// https://leetcode.com/problems/network-delay-time/solutions/5701275/simple-solution-using-dijkstra/
// Time complexity : O(Elog(n)) // e is no of edges
// Space complexity : O(n)

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : times)
        {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v, t});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> time(n + 1, 1e9);
        time[k] = 0;
        while (!pq.empty())
        {
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int wt = it.second;
                int ed = it.first;
                if (t + wt < time[ed])
                {
                    time[ed] = t + wt;
                    pq.push({t + wt, ed});
                }
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (time[i] == 1e9)
                return -1;
        }
        return *max_element(time.begin() + 1, time.end());
    }
};