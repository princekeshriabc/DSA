// Wildcard Matching
// https://leetcode.com/problems/wildcard-matching/solutions/5477337/simple-solution-in-c/
// time complexity = O(n*m)
// space complexity = O(n*m)

// memoization solution
class Solution
{
public:
    bool help(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (i >= 0 && j < 0)
        {
            for (int x = 0; x <= i; x++)
            {
                if (s[x] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] || s[i] == '?')
        {
            return dp[i][j] = help(i - 1, j - 1, s, p, dp);
        }
        else if (s[i] == '*')
        {
            return dp[i][j] = help(i - 1, j, s, p, dp) || help(i, j - 1, s, p, dp);
        }
        return false;
    }
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return help(m - 1, n - 1, p, s, dp);
    }
};