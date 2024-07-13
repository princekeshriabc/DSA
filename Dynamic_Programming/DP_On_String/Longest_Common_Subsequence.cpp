// Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/solutions/5469047/simple-solution-recursion-to-memoization/
// time complexity = O(n*n)
// space complexity = O(n*n)

// memoization solution
class Solution
{
public:
    int help(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (text1[ind1] == text2[ind2])
        {
            return dp[ind1][ind2] = 1 + help(ind1 - 1, ind2 - 1, text1, text2, dp);
        }
        return dp[ind1][ind2] = max(help(ind1, ind2 - 1, text1, text2, dp), help(ind1 - 1, ind2, text1, text2, dp));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return help(n - 1, m - 1, text1, text2, dp);
    }
};

// this solution will give TLE
class Solution
{
public:
    int help(int ind1, int ind2, string text1, string text2)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }
        if (text1[ind1] == text2[ind2])
        {
            return 1 + help(ind1 - 1, ind2 - 1, text1, text2);
        }
        return max(help(ind1, ind2 - 1, text1, text2), help(ind1 - 1, ind2, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        return help(text1.length() - 1, text2.length() - 1, text1, text2);
    }
};

