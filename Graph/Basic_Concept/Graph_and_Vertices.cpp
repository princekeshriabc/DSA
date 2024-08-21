// Graph and Vertices
// https://www.geeksforgeeks.org/problems/graph-and-vertices/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=graph-and-vertices
// time complexity = O(1)
// space complexity = O(1)

class Solution
{
public:
    long long count(int n)
    {
        // your code here
        return pow(2, (n * (n - 1) / 2));
    }
};