// Minimum path sum in Triangular Grid
// https://leetcode.com/problems/triangle/solutions/5419715/simple-solution-with-space-optimization/
// time complexity =O(n*n)
// space complexity =O(n) space optimization from dp tabulation

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int m = n;
        vector<int> last(m, 0), temp(m, 0);
        for (int i = 0; i < m; i++)
        {
            last[i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + last[j];
                int downd = triangle[i][j] + last[j + 1];
                temp[j] = min(down, downd);
            }
            last = temp;
        }
        return last[0];
    }
};