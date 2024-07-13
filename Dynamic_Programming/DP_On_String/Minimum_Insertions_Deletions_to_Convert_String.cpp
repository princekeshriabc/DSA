// Minimum Insertions/Deletions to Convert String
// https://leetcode.com/problems/delete-operation-for-two-strings/solutions/5472006/simple-solution-in-c-using-lcs/
// time complexity = O(n*m)
// space complexity = O(n*m)

class Solution
{
public:
    int lcs(int n, int m, string &s, string &t)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        int del = n - lcs(n, m, word1, word2);
        int ins = m - lcs(n, m, word1, word2);
        return del + ins;
    }
};