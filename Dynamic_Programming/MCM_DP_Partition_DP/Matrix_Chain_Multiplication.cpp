// Matrix Chain Multiplication
// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication
// time complexity = O(n*n*n)
// space complexity = O(n*n) +O(n)
// tabulation space complexity = O(n*n)

class Solution
{
public:
    int help(int i, int j, int N, int arr[], vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        for (int k = i; k < j; k++)
        {
            int cost = (arr[i - 1] * arr[k] * arr[j]) + help(i, k, N, arr, dp) + help(k + 1, j, N, arr, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return help(1, N - 1, N, arr, dp);
    }
};

// tabulation
int matrixMultiplication(int N, int arr[])
{
    // code here
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int cost = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}