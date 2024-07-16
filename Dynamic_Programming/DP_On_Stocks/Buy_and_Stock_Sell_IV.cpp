// Buy and Stock Sell IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/solutions/5484470/simple-solution-in-c-memoization-code/
// time complexity = O(n*k)
// space complexity = O(n*k)

class Solution
{
public:
    int help(int ind, int tran, int k, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind == n || tran == 2 * k)
        {
            return 0;
        }
        if (dp[ind][tran] != -1)
            return dp[ind][tran];
        if (tran % 2 == 0)
        {
            return dp[ind][tran] = max(-prices[ind] + help(ind + 1, tran + 1, k, n, prices, dp), help(ind + 1, tran, k, n, prices, dp));
        }
        return dp[ind][tran] = max(prices[ind] + help(ind + 1, tran + 1, k, n, prices, dp), help(ind + 1, tran, k, n, prices, dp));
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, -1));
        return help(0, 0, k, n, prices, dp);
    }
};