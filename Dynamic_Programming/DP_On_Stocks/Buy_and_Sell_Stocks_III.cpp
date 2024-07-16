// Buy and Sell Stocks III
// at most two transactions.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/solutions/5480531/simple-solution-in-c-memoization-solution-dp-n-4-solution/
// time complexity =O(n*4)
// space complexity =O(n*4)

class Solution
{
public:
    int help(int ind, int tran, vector<int> &prices, int &n, vector<vector<int>> &dp)
    {
        if (ind == n || tran == 4)
            return 0;
        if (dp[ind][tran] != -1)
            return dp[ind][tran];
        if (tran % 2 == 0)
        {
            return dp[ind][tran] = max(-prices[ind] + help(ind + 1, tran + 1, prices, n, dp), help(ind + 1, tran, prices, n, dp));
        }
        return dp[ind][tran] = max(prices[ind] + help(ind + 1, tran + 1, prices, n, dp), help(ind + 1, tran, prices, n, dp));
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));

        return help(0, 0, prices, n, dp);
    }
};