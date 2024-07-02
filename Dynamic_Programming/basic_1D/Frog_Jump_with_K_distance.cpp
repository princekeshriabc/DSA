// Frog jump with k distance
// https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost
// time complexity = O(n*k)
// space complexity = O(n)

int minimizeCost(vector<int> &height, int n, int k)
{
    // Code here
    vector<int> t(n + 1);
    t[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int mincost = INT_MAX;
        for (int j = 1; j <= k; j++)
        {

            if ((i - j) >= 0)
            {
                int cost = t[i - j] + abs(height[i] - height[i - j]);
                mincost = min(mincost, cost);
            }
        }
        t[i] = mincost;
    }
    return t[n - 1];
}