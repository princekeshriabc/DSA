// Jump Game
// https://leetcode.com/problems/jump-game/description/
// time complexity = O(n)
// space complexity = O(1)

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int maxind = 0;
        for (int i = 0; i < n; i++)
        {
            if (maxind < i)
                return false;
            int ind = i + nums[i];
            maxind = max(maxind, ind);
        }
        return maxind >= n - 1;
    }
};