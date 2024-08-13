// Job Sequencing Problem
// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
// Time Complexity = O(n)
// Space Complexity = O(max deadline)

class Solution
{
public:
    bool static comp(Job &a, Job &b)
    {
        return a.profit > b.profit;
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        int maxd = 0;
        for (int i = 0; i < n; i++)
        {
            maxd = max(maxd, arr[i].dead);
        }
        vector<int> v(maxd + 1, -1);
        int totalprofit = 0, count = 0;
        sort(arr, arr + n, comp);
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (v[j] == -1)
                {
                    totalprofit += arr[i].profit;
                    v[j] = arr[i].id;
                    count++;
                    break;
                }
            }
        }
        return {count, totalprofit};
    }
};