// Palindrome Partitioning - II
// https://leetcode.com/problems/palindrome-partitioning-ii/solutions/5505486/simple-solution-in-c-memoization/
// time complexity = O(n*n)
// space complexity = O(n)

class Solution
{
public:
    bool ispali(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int help(int i, int n, string &s, vector<int> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int mini = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (ispali(i, j, s))
            {
                int cost = 1 + help(j + 1, n, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return help(0, n, s, dp) - 1;
    }
};
