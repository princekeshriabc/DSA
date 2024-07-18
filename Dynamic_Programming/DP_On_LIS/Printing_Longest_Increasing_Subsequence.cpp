// Printing Longest Increasing Subsequence
// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence
// time complexity = O(n*n)
// space complexity = O(n)

vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
    // Code here
    vector<int> dp(n, 1), hash(n);
    int last = 0;
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev] && dp[i] < (1 + dp[prev]))
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (maxi < dp[i])
        {
            maxi = dp[i];
            last = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[last]);
    while (hash[last] != last)
    {
        last = hash[last];
        temp.push_back(arr[last]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
