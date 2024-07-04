// Grid Unique Path
// https://leetcode.com/problems/unique-paths/solutions/5408766/simple-solution-in-c-optimize-space-in-dp/
// time complexity =O(n*m)
// space complexity =O(n)

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                }
                else
                {
                    int p = 0, q = 0;
                    if (i > 0)
                    {
                        p = prev[j];
                    }
                    if (j > 0)
                        q = temp[j - 1];
                    temp[j] = p + q;
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};