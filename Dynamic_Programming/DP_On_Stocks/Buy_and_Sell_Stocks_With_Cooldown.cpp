// Buy and Sell Stocks With Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/5484521/simple-solution-in-c-recursion-memoization-solution/
// time complexity =O(n*2)  // for Memoization code
// space complexity =O(n*2)  

// Recursion Code
int help(int ind, int buy, int n, vector<int> &prices)
{
    if (ind >= n)
        return 0;
    if (buy)
    {
        return max(-prices[ind] + help(ind + 1, 0), help(ind + 1, 1));
    }
    return max(prices[ind] + help(ind + 2, 1), help(ind + 1, 0));
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    return help(0, 1, n, prices);
}

// Memoization code
class Solution
{
public:
    int help(int ind, int buy, int &n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind >= n)
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        if (buy)
        {
            return dp[ind][buy] = max(-prices[ind] + help(ind + 1, 0, n, prices, dp), help(ind + 1, 1, n, prices, dp));
        }
        return dp[ind][buy] = max(prices[ind] + help(ind + 2, 1, n, prices, dp), help(ind + 1, 0, n, prices, dp));
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return help(0, 1, n, prices, dp);
    }
};