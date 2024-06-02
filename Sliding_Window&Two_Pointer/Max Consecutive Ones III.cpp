int longestOnes(vector<int> &nums, int k)
{
    int l = 0, r = 0, maxlen = 0, zeroes = 0;
    while (r < nums.size())
    {
        if (nums[r] == 0)
            zeroes++;
        if (zeroes > k)
        {
            if (nums[l] == 0)
                zeroes--;
            l++;
        }
        else
        {
            maxlen = (maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}