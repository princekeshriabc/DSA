// Task Scheduler
// https://leetcode.com/problems/task-scheduler/solutions/5784490/simple-solution-in-c-beats-100/

// Time complexity:O(n+(26(log(26))))
// Space complexity : O(26)

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int time = 0;
        vector<int> freq(26);
        for (char task : tasks)
        {
            freq[task - 'A']++;
        }
        sort(freq.begin(), freq.end());
        int maxfreq = freq[25] - 1;
        int idleslot = maxfreq * n;
        for (int i = 24; i >= 0 && freq[i]; i--)
        {
            idleslot = idleslot - min(maxfreq, freq[i]);
        }
        if (idleslot > 0)
        {
            return idleslot + tasks.size();
        }
        else
        {
            return tasks.size();
        }
    }
};