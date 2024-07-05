// 3-d DP chocolate pickup
// https://www.geeksforgeeks.org/problems/chocolates-pickup/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=chocolates-pickup
// time complexity O(n*m*m)
// space complexity O(m*m) with space optimization code


int solve(int n, int m, vector<vector<int>> &grid)
{
    // code here
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> curr(m, vector<int>(m, 0));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                front[j1][j2] = grid[n - 1][j2];
            }
            else
            {
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e9;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                        {
                            value = grid[i][j1];
                        }
                        else
                        {
                            value += grid[i][j1] + grid[i][j2];
                        }
                        if ((j1 + dj1 >= 0 && j1 + dj1 < m) && (j2 + dj2 >= 0 && j2 + dj2 < m))
                        {
                            value += front[j1 + dj1][j2 + dj2];
                        }
                        else
                        {
                            value += -1e9;
                        }
                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][m - 1];
}