// Burst Balloons II
// https://leetcode.com/problems/burst-balloons/solutions/5505290/simple-solution-in-c-memoization/
// time complexity = O(n*n*n)
// space complexity = O(n*n) 

class Solution
{
public:
    int help(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxi = INT_MIN;
        for (int k = i; k <= j; k++)
        {
            int cost = nums[i - 1] * nums[k] * nums[j + 1] + help(i, k - 1, nums, dp) + help(k + 1, j, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return help(1, n, nums, dp);
    }
};