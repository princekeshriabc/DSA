// Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/solutions/5624613/simple-solution-in-c-time-limit-exceed-beat-100/

// Time complexity:O(nlog(k))
// Space complexity : O(k)

class KthLargest
{
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int it : nums)
        {
            pq.push(it);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }
    bool static comp(int a, int b)
    {
        return a > b;
    }
    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
        {
            pq.pop();
        }
        return pq.top();
    }
};