// Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/solutions/5697200/simple-solution-in-dijkstra-striver-approach/
// Time complexity : O(n∗mlog(n∗m))
//  complexity : O(n∗m)

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q; // <dis,{row,col}>
        q.push({0, {0, 0}});
        dist[0][0] = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while (!q.empty())
        {
            auto it = q.top();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == n - 1 && col == m - 1)
                return dis;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m)
                {

                    int maxi = max(dis, (abs(heights[row][col] - heights[nrow][ncol])));
                    // if(nrow==n-1 && ncol==m-1) return (abs(heights[row][col]-heights[nrow][ncol])+dis);
                    if (maxi < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = maxi;
                        q.push({maxi, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};