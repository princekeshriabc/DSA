// Unbounded Knapsack
// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items
// time complexity = O(n*W)
// space complexity = O(n*W)


int help(int ind, int w, int val[], int wt[], vector<vector<int>> &dp)
{
    if (w == 0)
    {
        return 0;
    }
    if (ind == 0)
    {
        return val[0] * (w / wt[0]);
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int notpick = help(ind - 1, w, val, wt, dp);
    int pick = 0;
    if (w >= wt[ind])
    {
        pick = val[ind] + help(ind, w - wt[ind], val, wt, dp);
    }
    return dp[ind][w] = max(notpick, pick);
}
int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return help(N - 1, W, val, wt, dp);
}