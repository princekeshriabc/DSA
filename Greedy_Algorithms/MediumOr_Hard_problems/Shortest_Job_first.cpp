// Shortest Job first
// https://www.geeksforgeeks.org/problems/shortest-job-first/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-job-first
// time complexity = O(nlog(n))
// space complexity = O(1)

class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        // code here
        sort(bt.begin(), bt.end());
        int n = bt.size();
        long long prefix = bt[0];
        long long sum = prefix;
        for (int i = 1; i < n - 1; i++)
        {
            prefix += bt[i];
            sum += prefix;
        }
        return sum / n;
    }
};
