// Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/solutions/5426478/simple-solution-in-c/
// time complexity= O(n* sum/2)
// space complexity= O(n* sum/2) sum is the sum of element in the array.

class Solution
{
public:
    bool help(int n, int sum, vector<int> &nums)
    {
        vector<vector<bool>> dp(n, vector<bool>((sum) + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if (sum >= nums[0])
        {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                bool notpick = dp[i - 1][j];
                bool pick = false;
                if (j >= nums[i])
                {
                    pick = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = pick || notpick;
            }
        }
        return dp[n - 1][sum];
    }
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        for (int it : nums)
        {
            sum += it;
        }
        if (sum & 1)
            return false;
        sum /= 2;
        return help(n, sum, nums);
    }
};