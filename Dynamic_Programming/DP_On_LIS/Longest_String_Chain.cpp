// Longest String Chain
// https://leetcode.com/problems/longest-string-chain/solutions/5490388/simple-solution-in-c/
// time complexity = O(n*n*len of maxlen string in the array)
// space complexity = O(n)

class Solution
{
public:
    bool help(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
            return false;
        int i = 0, j = 0;
        while (i < s1.size())
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (i == s1.size() && j == s2.size())
            return true;
        return false;
    }
    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        int maxi = 1;
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (help(words[i], words[prev]) && dp[i] < 1 + dp[prev])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            if (maxi < dp[i])
            {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};