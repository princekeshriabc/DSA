#include <bits/stdc++.h>
using namespace std;

// string DecimalToBinary(int n)
// {
//     string res = "";
//     while (n)
//     {
//         if (n % 2 == 0)
//             res += '0';
//         else
//             res += '1';
//         n /= 2;
//     }
//     reverse(res.begin(), res.end());
//     return res;
// }

// using bit manipulation 
// TC = O(logn) SC = O(logn)
string DecimalToBinary(int n)
{
    string res = "";
    while (n)
    {
        if (n & 1) // 1
            res += '1';
        else // 0
            res += '0';
        n = n >> 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << "Binary of num 59 is: "<<DecimalToBinary(n);
    return 0;
}