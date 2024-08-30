// Find the city with the smallest number of neighbors in a threshold distance
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solutions/5709616/simple-solution-using-floyd-warshall-striver-approach/
// Time complexity : O(n∗n∗n)
// Space complexity : O(n∗n)

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        for (auto it : edges)
        {
            matrix[it[0]][it[1]] = it[2];
            matrix[it[1]][it[0]] = it[2];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (i == j)
                    matrix[i][j] = 0;
            }
        }
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
        int maxc = n + 1;
        int node = -1;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            if (maxc >= count)
            {
                maxc = count;
                node = i;
            }
        }
        return node;
    }
};