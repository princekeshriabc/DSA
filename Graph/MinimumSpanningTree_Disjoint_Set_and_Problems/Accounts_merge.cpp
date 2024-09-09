// Accounts merge
// https://leetcode.com/problems/accounts-merge/solutions/5741447/simple-solution-using-disjoint-set-striver-approach/

class DisjointSet
{
public:
    vector<int> parent, rank;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUpar(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findUpar(parent[u]);
    }
    void unionByRank(int u, int v)
    {
        int upu = findUpar(u);
        int upv = findUpar(v);
        if (upu == upv)
            return;
        if (rank[upu] < rank[upv])
        {
            parent[upu] = upv;
        }
        else if (rank[upu] > rank[upv])
        {
            parent[upv] = upu;
        }
        else
        {
            parent[upv] = upu;
            rank[upu]++;
        }
    }
};
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mailtonode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mailtonode.find(mail) == mailtonode.end())
                {
                    mailtonode[mail] = i;
                }
                else
                {
                    ds.unionByRank(i, mailtonode[mail]);
                }
            }
        }

        vector<string> detail[n];
        for (auto it : mailtonode)
        {
            string mail = it.first;
            int node = ds.findUpar(it.second);
            detail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (detail[i].size() == 0)
                continue;
            sort(detail[i].begin(), detail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : detail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};