// Minimum Falling Path Sum
// https://leetcode.com/problems/minimum-falling-path-sum/solutions/5420194/simple-solution-tabulation-and-space-optimization-both-solution/
// time Complexity = O(n*m)
// Space Complexity = O(n*m) for tabulation solution
// Space Complexity = O(n) for space optimization solution


// tabulation solution
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> t(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            t[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = matrix[i][j] + t[i - 1][j];
                int ld = matrix[i][j];
                if (j - 1 >= 0)
                {
                    ld += t[i - 1][j - 1];
                }
                else
                {
                    ld += 1e9;
                }
                int rd = matrix[i][j];
                if (j + 1 < m)
                {
                    rd += t[i - 1][j + 1];
                }
                else
                {
                    rd += 1e9;
                }
                t[i][j] = min(up, min(ld, rd));
            }
        }
        int mini = t[n - 1][0];
        for (int j = 1; j < m; j++)
        {
            mini = min(mini, t[n - 1][j]);
        }
        return mini;
    }
};

// Space optimization solution
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        for (int i = 0; i < m; i++)
        {
            prev[i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = matrix[i][j] + prev[j];
                int ld = matrix[i][j];
                if (j - 1 >= 0)
                {
                    ld += prev[j - 1];
                }
                else
                {
                    ld += 1e9;
                }
                int rd = matrix[i][j];
                if (j + 1 < m)
                {
                    rd += prev[j + 1];
                }
                else
                {
                    rd += 1e9;
                }
                curr[j] = min(up, min(ld, rd));
            }
            prev = curr;
        }
        int mini = prev[0];
        for (int j = 1; j < m; j++)
        {
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};