//  Number of Islands II
// https://www.naukri.com/code360/problems/number-of-islands-ii_1266048?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
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
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{
    // Write your code here.
    DisjointSet ds(n * m);
    vector<int> ans;
    int count = 0;
    int vis[n][m];
    memset(vis, 0, sizeof vis);
    for (auto it : q)
    {
        int row = it[0];
        int col = it[1];
        if (vis[row][col] == 1)
        {
            ans.push_back(count);
            continue;
        }
        count++;
        vis[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 1)
            {
                int node = (row * m) + col;
                int node1 = (nrow * m) + ncol;
                if (ds.findUpar(node) != ds.findUpar(node1))
                {
                    count--;
                    ds.unionByRank(node, node1);
                }
            }
        }
        ans.push_back(count);
    }
    return ans;
}