// Count Partitions with Given Difference
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference
// time complexity =O(n*sum)
// space complexity = O(n*sum)+O(n)


int help(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (sum == 0 && arr[0] == 0)
            return 2;
        if (sum == 0 || sum == arr[0])
            return 1;
        return 0;
    }
    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int notpick = help(ind - 1, sum, arr, dp);
    int pick = 0;
    if (arr[ind] <= sum)
    {
        pick = help(ind - 1, sum - arr[ind], arr, dp);
    }
    return dp[ind][sum] = (pick + notpick) % 1000000007;
}
int countPartitions(int n, int d, vector<int> &arr)
{
    // Code here
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    int sum = (total - d) / 2;
    if (total - d < 0)
        return 0;
    if ((total - d) % 2 == 1)
        return 0;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return help(n - 1, sum, arr, dp);
}