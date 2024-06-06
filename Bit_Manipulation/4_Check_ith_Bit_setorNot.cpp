// Check the ith bit is set or not 

//using left shift
bool Check_ith_Bit_setorNot(int n,int i){
    if(n&(1<<i)){
        return true;
    }
    else{
        return false;
    }
    return true;
}

////using right shift
bool Check_ith_Bit_setorNot(int n, int i)
{
    if ((n>>i)&1)
    {
        return true;
    }
    else
    {
        return false;
    }
    return true;
}