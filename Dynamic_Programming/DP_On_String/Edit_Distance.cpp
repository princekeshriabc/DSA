// Edit Distance
// https://leetcode.com/problems/edit-distance/solutions/5477237/simple-solution-in-c/
// time complexity = O(n*m)
// space complexity = O(n*m)


// memoization solution
class Solution
{
public:
    int help(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i] == word2[j])
        {
            return dp[i][j] = help(i - 1, j - 1, word1, word2, dp);
        }
        return dp[i][j] = 1 + min(help(i - 1, j - 1, word1, word2, dp), min(help(i - 1, j, word1, word2, dp), help(i, j - 1, word1, word2, dp)));
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return help(n - 1, m - 1, word1, word2, dp);
    }
};