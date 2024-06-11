// Find Prime Factorisation of a Number using Sieve
// Time Complexity: O(nlog(logn))

vector<int> findPrimeFactors(int N)
{

    // Write your code here
    int v[200000];
    for (int i = 0; i <= N; i++)
    {
        v[i] = i;
    }
    for (int i = 2; (i * i) <= N; i++)
    {
        if (v[i] == i)
        {
            int j = i * i;
            while (j <= N)
            {
                if (v[j] == j)
                {
                    v[j] = i;
                }
                j += i;
            }
        }
    }
    vector<int> factor;
    while (N != 1)
    {
        factor.push_back(v[N]);
        N /= v[N];
    }
    return factor;
}