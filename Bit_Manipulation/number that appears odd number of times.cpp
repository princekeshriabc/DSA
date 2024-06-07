// Find the number that appears odd number of times

int singleNumber(vector<int> &nums)
{
    int temp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        temp = temp ^ nums[i];
    }
    return temp;
}