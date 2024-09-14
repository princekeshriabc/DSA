// Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/solutions/5785484/simple-solution-only-think-and-write-maxheap/

// Time complexity:O(n)
// Space complexity : O(n)

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto it : nums)
        {
            mp[it]++;
        }
        priority_queue<pair<int, int>> p;
        for (auto it : mp)
        {
            p.push({it.second, it.first});
        }
        vector<int> ans;
        while (k--)
        {
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};