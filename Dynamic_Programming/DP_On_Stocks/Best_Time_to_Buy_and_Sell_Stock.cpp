// Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/5477369/simple-solution-in-c/
// time complexity = O(n)
// space complexity = O(1)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int profit = 0;
        for (int num : prices)
        {
            profit = max(num - mini, profit);
            mini = min(mini, num);
        }
        return profit;
    }
};
