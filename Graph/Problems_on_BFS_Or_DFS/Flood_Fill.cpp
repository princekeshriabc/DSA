// Flood Fill
// https://leetcode.com/problems/flood-fill/description/
// time complexity = O(V+E)
// space complexity = O(V)

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        queue<pair<pair<int, int>, int>> q;
        q.push({{sr, sc}, color});

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = image[i][j];
            }
        }
        int oricolour = image[sr][sc];
        vis[sr][sc] = color;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int color = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newrow = r + delrow[i];
                int newcol = c + delcol[i];
                if (newrow < n && newrow >= 0 && newcol < m && newcol >= 0 && vis[newrow][newcol] != color && image[newrow][newcol] == oricolour)
                {
                    vis[newrow][newcol] = color;
                    q.push({{newrow, newcol}, color});
                }
            }
        }
        return vis;
    }
};