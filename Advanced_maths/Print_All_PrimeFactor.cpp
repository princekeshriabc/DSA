//Print all prime factor of a number
// TC =O(sqrt(n)*log(n)) SC = O(n)

vector<int> AllPrimeFactors(int N)
{
    // Code here
    vector<int> v;
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            v.push_back(i);
            while (N % i == 0)
            {
                N = N / i;
            }
        }
    }
    if (N != 1)
        v.push_back(N);
    return v;
}