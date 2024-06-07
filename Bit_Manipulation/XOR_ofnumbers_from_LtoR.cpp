// Find XOR of numbers from L to R

int solve(int n)
{
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}
int findXOR(int l, int r)
{
    // complete the function here
    return solve(l - 1) ^ solve(r);
}