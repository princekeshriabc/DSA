// Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/solutions/5490291/simple-solution-in-c/
// // time complexity = O(n*n)
// space complexity = O(n)

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = 1, last = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (maxi < dp[i])
            {
                maxi = dp[i];
                last = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[last]);
        while (hash[last] != last)
        {
            last = hash[last];
            temp.push_back(nums[last]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};