// Maximum Rectangle Area with all 1's
// https://leetcode.com/problems/maximal-rectangle/solutions/5611145/simple-solution-in-c-dp/
// time complexity = O(n*m)
// space complexity = O(n)

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 0;
        vector<int> v(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0')
                {
                    v[j] = 0;
                }
                else
                {
                    v[j] += 1;
                }
            }
            stack<int> st;
            vector<int> r(n);
            for (int k = n - 1; k >= 0; k--)
            {
                if (st.empty())
                {
                    r[k] = n;
                }
                else
                {
                    while (!st.empty() && v[st.top()] >= v[k])
                    {
                        st.pop();
                    }
                    if (st.empty())
                    {
                        r[k] = n;
                    }
                    else
                    {
                        r[k] = st.top();
                    }
                }
                st.push(k);
            }
            stack<int> st1;
            vector<int> l(n);
            for (int k = 0; k < n; k++)
            {
                if (st1.empty())
                {
                    l[k] = -1;
                }
                else
                {
                    while (!st1.empty() && v[st1.top()] >= v[k])
                    {
                        st1.pop();
                    }
                    if (st1.empty())
                    {
                        l[k] = -1;
                    }
                    else
                    {
                        l[k] = st1.top();
                    }
                }
                st1.push(k);
            }
            for (int k = 0; k < n; k++)
            {
                int area = v[k] * (r[k] - l[k] - 1);
                maxi = max(maxi, area);
            }
        }

        return maxi;
    }
};