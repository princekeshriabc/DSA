// Partition Array for Maximum Sum
// https://leetcode.com/problems/partition-array-for-maximum-sum/solutions/5505596/simple-solution-in-c-memoization/
// // time complexity = O(n*k)
// space complexity = O(n)

class Solution
{
public:
    int help(int ind, int n, vector<int> &arr, int k, vector<int> &dp)
    {
        if (ind == n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int len = 0;
        int ans = INT_MIN;
        int maxi = INT_MIN;
        for (int j = ind; j < min(n, ind + k); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + help(j + 1, n, arr, k, dp);
            ans = max(ans, sum);
        }
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        return help(0, n, arr, k, dp);
    }
};
