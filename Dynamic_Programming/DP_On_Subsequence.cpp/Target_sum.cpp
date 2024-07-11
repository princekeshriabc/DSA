// Target sum
// https://leetcode.com/problems/target-sum/solutions/5459291/simple-solution-in-c-memoization-solution/
// time complexity = O(n*sum)
// space complexity = O(n*sum)

class Solution
{
public:
    int help(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (sum == 0 && arr[0] == 0)
                return 2;
            if (sum == 0 || sum == arr[0])
                return 1;
            return 0;
        }
        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        int notpick = help(ind - 1, sum, arr, dp);
        int pick = 0;
        if (arr[ind] <= sum)
        {
            pick = help(ind - 1, sum - arr[ind], arr, dp);
        }
        return dp[ind][sum] = (pick + notpick) % 1000000007;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        int sum = (total - target) / 2;
        if ((total - target) & 1)
        {
            return 0;
        }
        if (total - target < 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return help(n - 1, sum, nums, dp);
    }
};