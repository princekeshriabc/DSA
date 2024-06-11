// using this Sieve of Eratosthenes for count prime number till n
// Time Complexity: O(nlog(logn))

int countPrimes(int n)
{
    vector<int> v(n + 1, 1);
    int count = 0;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (v[i] == 1)
        {
            int j = i * i;
            ;
            while (j <= n)
            {
                v[j] = 0;
                j += i;
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (v[i] == 1)
            count++;
    }
    return count;
}