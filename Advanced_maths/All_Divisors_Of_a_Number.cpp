// print the all divisors of a number
// Time Complexity: O(sqrt(n))
// Space Complexity: O(sqrt(n))

void print_divisors(int n)
{
    vector<int> v;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (i != (n / i))
                v.push_back(n / i);
            ;
        }
    }
    sort(v.begin(), v.end());
    for (auto it : v)
    {
        cout << it << " ";
    }
}