// find the minimum number of bit flips to convert a nuber to another number 
//TC = O(log(n)) SC = O(1)

int Min_Bit_Convert_Number(int n,int m){
    int count = 0;
    int a = n ^ m;
    while (a != 0)
    {
        n = n & n - 1;
        count++;
    }
    return count;
}