// Convert Min Heap to Max Heap
// https: // www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=convert-min-heap-to-max-heap

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[i])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
class Solution
{
public:
    void convertMinToMaxHeap(vector<int> &arr, int n)
    {
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }
};