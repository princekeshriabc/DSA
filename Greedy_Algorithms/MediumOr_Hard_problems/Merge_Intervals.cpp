// Merge Intervals
// https://leetcode.com/problems/merge-intervals/solutions/5625171/simple-solution-in-c/
// time complexity = O(n)
// space complexity = O(n*n)

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> temp;
        int n = intervals.size();
        temp = intervals[0];
        for (auto it : intervals)
        {
            if (it[0] <= temp[1])
            {
                temp[1] = max(temp[1], it[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};