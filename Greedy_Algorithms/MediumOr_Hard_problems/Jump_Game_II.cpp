// Jump Game II
// https://leetcode.com/problems/jump-game-ii/description/
// // time complexity = O(n)
// space complexity = O(1)

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        int l = 0, r = 0;
        while (r < n - 1)
        {
            int maxind = 0;
            for (int i = l; i <= r; i++)
            {
                maxind = max(maxind, i + nums[i]);
            }
            l = r + 1;
            r = maxind;
            count++;
        }
        return count;
    }
};