// Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/5774901/simple-solution-using-min-heap-100-beats/

// Time complexity : O(n(log(k)))
// Space complexity : O(k)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> p;
        for (int i = 0; i < k; i++)
        {
            p.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++)
        {
            if (p.top() < nums[i])
            {
                p.pop();
                p.push(nums[i]);
            }
        }
        return p.top();
    }
};