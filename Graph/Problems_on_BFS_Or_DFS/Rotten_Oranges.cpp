// Rotten Oranges
// https://leetcode.com/problems/rotting-oranges/solutions/5667902/simpe-solution-in-c-striver/
// time complexity = O(V+E)
// space complexity = O(V)

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        int freshcount = 0;
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                else
                {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    freshcount++;
            }
        }
        int time = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        int count = 0;
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for (int i = 0; i < 4; i++)
            {
                int newrow = r + delrow[i];
                int newcol = c + delcol[i];
                if (newrow < n && newrow >= 0 && newcol < m && newcol >= 0 && vis[newrow][newcol] != 2 && grid[newrow][newcol] == 1)
                {
                    vis[newrow][newcol] = 2;
                    q.push({{newrow, newcol}, t + 1});
                    count++;
                }
            }
        }
        if (count != freshcount)
            return -1;
        return time;
    }
};