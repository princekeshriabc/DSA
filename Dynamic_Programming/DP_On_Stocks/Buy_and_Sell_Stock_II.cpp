// Buy and Sell Stock - II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solutions/5479707/simple-solution-in-c-dp-space-optimization/\
// time complexity = O(n*2)
// space complexity = O(2)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> prev(2, 0), curr(2, 0);
        prev[0] = prev[1] = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[ind] + prev[0], prev[1]);
                }
                else
                {
                    profit = max(prices[ind] + prev[1], prev[0]);
                }
                curr[buy] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
};