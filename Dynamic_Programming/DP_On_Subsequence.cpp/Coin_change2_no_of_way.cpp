// coin change problem 2
// https://leetcode.com/problems/coin-change-ii/solutions/5459425/simple-solution-in-c-space-optimization-solution-o-amount/
// time complexity = O(n*amount)
// space complexity = O(amount) space optimize solution 

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);
        for (int t = 0; t < amount + 1; t++)
        {
            prev[t] = (t % coins[0] == 0);
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int t = 0; t < amount + 1; t++)
            {
                int notpick = prev[t];
                int pick = 0;
                if (t >= coins[ind])
                {
                    pick = curr[t - coins[ind]];
                }
                curr[t] = pick + notpick;
            }
            prev = curr;
        }
        return prev[amount];
    }
};