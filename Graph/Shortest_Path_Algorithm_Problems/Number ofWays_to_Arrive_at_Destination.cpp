// Number of Ways to Arrive at Destination
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/solutions/5708327/simple-solution-striver-approach-use-long-long-int-instead-of-int/
// Time complexity : O(roads.size() log(n))
// Space complexity : O(n)

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long int> ways(n, 0);
        vector<long long int> time(n, LLONG_MAX);
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
        pq.push({0, 0});
        ways[0] = 1;
        time[0] = 0;
        int mod = (int)1e9 + 7;
        while (!pq.empty())
        {
            long long int node = pq.top().second;
            long long int tim = pq.top().first;
            pq.pop();
            for (auto it : adj[node])
            {
                long long int ed = it.first;
                long long int wt = it.second;
                if ((wt + tim) < time[ed])
                {
                    time[ed] = wt + tim;
                    pq.push({wt + tim, ed});
                    ways[ed] = ways[node];
                }
                else if (wt + tim == time[ed])
                {
                    ways[ed] = (ways[ed] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};