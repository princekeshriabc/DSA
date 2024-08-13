// N meetings in one room
// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// time complexity = O(nlog(n))
// space complexity = O(n*n)

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    bool static comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int maxMeetings(int n, int start[], int end[])
    {
        // Your code here
        vector<vector<int>> pairs;
        for (int i = 0; i < n; i++)
        {
            pairs.push_back({start[i], end[i]});
        }
        int count = 1;
        sort(pairs.begin(), pairs.end(), comp);
        int endchain = pairs[0][1];
        for (int i = 1; i < n; i++)
        {
            if (pairs[i][0] > endchain)
            {
                count++;
                endchain = pairs[i][1];
            }
        }
        return count;
    }
};