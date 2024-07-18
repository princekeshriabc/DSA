// Number of Longest Increasing Subsequences
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/solutions/5490992/simple-solution-in-c/
// time complexity = O(n*n)
// space complexity = O(n)

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = 1;
        vector<int> dp(n, 1), ct(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev] && dp[i] < 1 + dp[prev])
                {
                    dp[i] = 1 + dp[prev];
                    ct[i] = ct[prev];
                }
                else if (nums[i] > nums[prev] && dp[i] == 1 + dp[prev])
                {
                    ct[i] += ct[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
            {
                count += ct[i];
            }
        }
        return count;
    }
};