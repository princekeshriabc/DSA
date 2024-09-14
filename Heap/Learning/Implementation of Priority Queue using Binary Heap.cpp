// Implementation of Priority Queue using Binary Heap
// https://www.geeksforgeeks.org/problems/implementation-of-priority-queue-using-binary-heap/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementation-of-priority-queue-using-binary-heap

class Solution
{
public:
    int extractMax()
    {
        // your code here
        int x = H[0];
        swap(H[0], H[s]);
        s--;
        shiftDown(0);
        return x;
    }
};