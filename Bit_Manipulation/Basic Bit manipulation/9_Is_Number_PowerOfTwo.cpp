// check number is Power of 2 or not

bool Is_Power_Of_Two(int n)
{
    if ((n & (n - 1)) == 0)
        return true;
    else
        return false;
    return true;
}