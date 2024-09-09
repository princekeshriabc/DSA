// Making A Large Island
// https://leetcode.com/problems/making-a-large-island/solutions/5742762/simple-solution-using-disjoint-set-striver-approach/
// time complexity = O(n*n)
// space complexity = O(n*n)

class DisjointSet
{
public:
    vector<int> parent, rank, Size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        Size.resize(n + 1, 1);
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
    void unionBySize(int u, int v)
    {
        int upu = findUpar(u);
        int upv = findUpar(v);
        if (upu == upv)
            return;
        if (rank[upu] < rank[upv])
        {
            parent[upu] = upv;
            Size[upv] += Size[upu];
        }
        else
        {
            parent[upv] = upu;
            Size[upu] += Size[upv];
        }
    }
};
class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    continue;
                int delr[] = {-1, 0, 1, 0};
                int delc[] = {0, -1, 0, 1};
                for (int k = 0; k < 4; k++)
                {
                    int nrow = i + delr[k];
                    int ncol = j + delc[k];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && grid[nrow][ncol] == 1)
                    {
                        int node = i * n + j;
                        int adjnode = nrow * n + ncol;
                        ds.unionBySize(node, adjnode);
                    }
                }
            }
        }
        int maxi = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;
                int delr[] = {-1, 0, 1, 0};
                int delc[] = {0, -1, 0, 1};
                set<int> st;
                for (int k = 0; k < 4; k++)
                {
                    int nrow = row + delr[k];
                    int ncol = col + delc[k];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && grid[nrow][ncol] == 1)
                    {
                        int up = ds.findUpar(nrow * n + ncol);
                        st.insert(up);
                    }
                }
                int ans = 0;
                for (auto it : st)
                    ans += ds.Size[it];
                maxi = max(maxi, ans + 1);
            }
        }
        for (int i = 0; i < n * n; i++)
        {
            maxi = max(maxi, ds.Size[ds.findUpar(i)]);
        }
        return maxi;
    }
};