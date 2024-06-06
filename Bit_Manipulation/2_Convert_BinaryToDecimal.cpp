#include <bits/stdc++.h>
using namespace std;

int BinaryToDecimal(string str)
{
    int p = 1,num=0;
    for (int i = str.length()-1; i >= 0;i--){
        if(str[i]=='1'){
            num += p;
        }
        p *= 2;
    }
    return num;
}
int main()
{
    string n;
    cin >> n;
    cout << BinaryToDecimal(n);
    return 0;
}