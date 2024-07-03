// Maximum sum of non-adjacent elements
// https://leetcode.com/problems/house-robber/solutions/5407854/simple-solution-in-c/
// time complexity = O(n)
// spcae complexity = O(n)

// Memoization code 
int help(int n, vector<int> &nums, vector<int> &t)
{
    if (n == 0)
    {
        return nums[0];
    }
    if (n < 0)
    {
        return 0;
    }
    if (t[n] != -1)
    {
        return t[n];
    }
    int pick = nums[n] + help(n - 2, nums, t);
    int notpick = 0 + help(n - 1, nums, t);
    return t[n] = max(pick, notpick);
}
int rob(vector<int> &nums)
{
    vector<int> t(nums.size(), -1);
    return help(nums.size() - 1, nums, t);
}

// tabulation/bottom up solution
int rob(vector<int> &nums)
{
    if (nums.size() < 2)
        return nums[0];

    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++)
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    return dp[nums.size() - 1];
}