// Buy and Sell Stocks With Transaction Fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/5484573/simple-solution-in-c-memoization-code/
// time complexity =O(n*2)
// space complexity =O(n*2)

class Solution
{
public:
    int help(int ind, int buy, int &fee, int &n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind == n)
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        if (buy)
        {
            return dp[ind][buy] = max(-prices[ind] + help(ind + 1, 0, fee, n, prices, dp), help(ind + 1, 1, fee, n, prices, dp));
        }
        return dp[ind][buy] = max(prices[ind] - fee + help(ind + 1, 1, fee, n, prices, dp), help(ind + 1, 0, fee, n, prices, dp));
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return help(0, 1, fee, n, prices, dp);
    }
};