// Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/solutions/5785454/simple-solution-using-two-heap-leftmaxheap-rightminheap-beat-100/

// Time complexity : O(klog(n))
// Space complexity : O(n)

class MedianFinder
{
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {}

    void addNum(int num)
    {
        if (left.size() == 0)
        {
            left.push(num);
            return;
        }

        if (num > left.top())
        {
            right.push(num);
        }
        else
        {
            left.push(num);
        }
        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (left.size() < right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian()
    {
        if (left.size() > right.size())
        {
            return left.top();
        }
        else
        {
            return (left.top() + right.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */