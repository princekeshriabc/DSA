// Assign Cookies
// https://leetcode.com/problems/assign-cookies/description/
// time complexity = O(nlog(n)+mlog(m))
// space complexity = O(1)

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, r = 0;
        while (l < m && r < n)
        {
            if (s[l] >= g[r])
            {
                l++;
                r++;
            }
            else
            {
                l++;
            }
        }
        return r;
    }
};