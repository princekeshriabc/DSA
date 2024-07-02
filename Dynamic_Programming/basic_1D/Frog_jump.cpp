// Frog jump
// https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump
// time complexity=O(n)
// space complexity=O(n)

int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(height[i] - height[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = dp[i - 2] + abs(height[i] - height[i - 2]);
        dp[i] = min(fs, ss);
    }
    return dp[n - 1];
}