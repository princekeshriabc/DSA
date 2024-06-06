// clear the ith bit of the number

int Clear_Ith_Bit(int n, int i)
{
    return (n & ~(1 << i));
}