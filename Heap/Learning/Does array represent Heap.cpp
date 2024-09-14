// Does array represent Heap
// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=does-array-represent-heap

class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int i = 0;

        while (i < n)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (arr[i] < arr[left])
                return false;
            if (arr[right] > arr[i])
                return false;
            i++;
        }
        return true;
    }
};