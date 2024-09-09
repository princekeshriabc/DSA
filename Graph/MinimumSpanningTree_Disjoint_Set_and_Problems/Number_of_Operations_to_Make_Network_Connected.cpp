// Number of Operations to Make Network Connected
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/solutions/5740306/simple-solution-using-disjoint-set-striver-approach/

// Time complexity : O(n∗m)
// Space complexity : O(n)

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
        if (upv == upu)
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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);
        int extraedge = 0;
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findUpar(u) == ds.findUpar(v))
                extraedge++;
            else
            {
                ds.unionByRank(u, v);
            }
        }
        int noc = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                noc++;
        }
        if (noc - 1 <= extraedge)
            return noc - 1;
        return -1;
    }
};