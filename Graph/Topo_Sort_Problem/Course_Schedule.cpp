// Course Schedule
// https://leetcode.com/problems/course-schedule/solutions/5692118/simple-solution-using-bfs-striver-approach/
// time complexity =O(v+E)
// space complexity =O(v)

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        int n = prerequisites.size();
        for (int i = 0; i < n; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int V = numCourses;
        unordered_map<int, int> ind;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                ind[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for (auto it : adj[node])
            {
                ind[it]--;
                if (ind[it] == 0)
                    q.push(it);
            }
        }
        if (count == V)
            return true;
        return false;
    }
};