// count the number of set bit in a number

int Count_Set_Bit(int n){
    int c = 0;
    while(n){
        c += n & 1;
        n =n>>1;
    }
    return c;
}

//second method
int Count_Set_Bit(int n)
{
    int c = 0;
    while (n!=0)
    {
        n = n & n - 1;
        c++;
    }
    return c;
}