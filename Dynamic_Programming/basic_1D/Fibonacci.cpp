// find fibonacci
// https://www.geeksforgeeks.org/problems/introduction-to-dp/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-dp

// both topdown and buttom code
const long long int MOD = 1e9 + 7;
class Solution
{
public:
    long long int memo(int n, vector<long long int> &t)
    {
        if (n <= 1)
            return n;
        if (t[n] != -1)
        {
            return t[n];
        }
        t[n] = (memo(n - 1, t) + memo(n - 2, t)) % MOD;
        return t[n];
    }
    long long int topDown(int n)
    {
        // code here
        vector<long long int> t(n + 1, -1);
        return memo(n, t);
    }
    long long int bottomUp(int n)
    {
        // code here
        if (n <= 1)
            return n;
        vector<long long int> a(n + 1);
        a[0] = 0;
        a[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            a[i] = (a[i - 1] + a[i - 2]) % MOD;
        }
        return a[n];
    }
};