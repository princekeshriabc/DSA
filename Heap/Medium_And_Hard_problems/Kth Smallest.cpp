// Kth Smallest
// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=kth-smallest-element

class Solution
{
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {
        // code here
        priority_queue<int> p;
        for (int i = 0; i < k; i++)
        {
            p.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++)
        {
            if (p.top() > arr[i])
            {
                p.pop();
                p.push(arr[i]);
            }
        }
        return p.top();
    }
};