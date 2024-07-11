// Minimum Coins
// https://leetcode.com/problems/coin-change/solutions/5459621/simple-solution-in-o-amount-space-space-optimization-solution/
// time complexity = O(n*amount)
// space complexity = O(amount)

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, INT_MAX - 1);
        vector<int> curr(amount + 1, INT_MAX - 1);
        for (int j = 0; j <= amount; j++)
        {
            if ((j % coins[0]) == 0)
            {
                prev[j] = j / coins[0];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int notpick = prev[j];
                int pick = INT_MAX - 1;
                if (j >= coins[i])
                {
                    pick = 1 + curr[j - coins[i]];
                }
                curr[j] = min(pick, notpick);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if (ans >= INT_MAX - 1)
            return -1;
        return ans;
    }
};