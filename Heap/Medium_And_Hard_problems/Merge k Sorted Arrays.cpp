// Merge k Sorted Arrays
// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-k-sorted-arrays

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        // code here
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < k; i++)
            if (!arr[i].empty())
                v.push_back(make_pair((arr[i][0]), make_pair(i, 0)));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(v.begin(), v.end());
        pair<int, pair<int, int>> ele;
        int i, j;
        vector<int> ans;
        while (!p.empty())
        {
            ele = p.top();
            p.pop();
            i = ele.second.first;
            j = ele.second.second;
            ans.push_back(ele.first);
            if (j + 1 < k)
                p.push(make_pair((arr[i][j + 1]), make_pair(i, j + 1)));
        }
        return ans;
    }
};