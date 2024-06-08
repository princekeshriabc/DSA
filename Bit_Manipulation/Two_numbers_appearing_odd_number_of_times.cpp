// Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

vector<long long int> twoOddNum(long long int Arr[], long long int n)
{
    // code here
    long long int temp = 0;
    for (long long int i = 0; i < n; i++)
    {
        temp = temp ^ Arr[i];
    }
    long long int rightmost = (temp & (temp - 1)) ^ temp;
    long long int b1 = 0, b2 = 0;

    for (long long int i = 0; i < n; i++)
    {
        if (rightmost & Arr[i])
        {
            b1 ^= Arr[i];
        }
        else
        {
            b2 ^= Arr[i];
        }
    }
    if (b1 < b2)
        return {b2, b1};
    return {b1, b2};
}