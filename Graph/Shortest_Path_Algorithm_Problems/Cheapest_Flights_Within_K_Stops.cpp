// Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/solutions/5697776/simple-solution-using-bfs-striver-approach/
// Time complexity : O(e) // E is size of the flights
// Space complexity : O(n)

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> price(n, 1e9);
        price[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // {steps,{node,price}}
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (steps > k)
                continue;
            for (auto itt : adj[node])
            {
                int eg = itt.first;
                int pri = itt.second;
                if (pri + cost < price[eg] && steps <= k)
                {
                    price[eg] = pri + cost;
                    q.push({steps + 1, {eg, pri + cost}});
                }
            }
        }
        if (price[dst] == 1e9)
            return -1;
        return price[dst];
    }
};