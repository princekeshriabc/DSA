// Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/solutions/5490217/simple-solution-in-o-n-log-n/
// time complexity = O(n log(n))
// space complexity = O(n)

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> temp;
        temp.push_back(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};