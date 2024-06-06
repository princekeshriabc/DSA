// Remove Last Set Bit of the number

int Remove_Last_Set_Bit(int n)
{
    return n & (n - 1);
}