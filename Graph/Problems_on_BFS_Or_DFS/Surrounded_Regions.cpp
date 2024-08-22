// Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/solutions/5673049/simple-solution-in-c-striver/

// time complexity = O(N*M)
// space complexity = O(N*M)

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int delrow[], int delcol[])
    {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                vis[i][0] = 1;
                dfs(i, 0, vis, board, delrow, delcol);
            }
            if (board[i][m - 1] == 'O')
            {
                vis[i][m - 1] = 1;
                dfs(i, m - 1, vis, board, delrow, delcol);
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
            {
                vis[0][j] = 1;
                dfs(0, j, vis, board, delrow, delcol);
            }
            if (board[n - 1][j] == 'O')
            {
                vis[n - 1][j] = 1;
                dfs(n - 1, j, vis, board, delrow, delcol);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};