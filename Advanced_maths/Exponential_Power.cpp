// find the pow (x,n)
// Time Complexity = O(log(n))

double myPow(double x, int n)
{
    double ans = 1;
    if (n < 0)
    {
        x = 1 / x;
    }
    long m = labs(n);

    while (m != 0)
    {
        if (m & 1)
        {
            ans *= x;
        }
        x *= x;
        m >>= 1;
    }
    return ans;
}