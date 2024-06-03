// TC = O(N)  SC=O(1) with two pointer and sliding window 

int count1(vector<int> &nums, int goal)
{
    int l = 0, r = 0, sum = 0, count = 0;
    while (r < nums.size())
    {
        sum += nums[r];
        while (sum > goal)
        {
            sum -= nums[l];
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    return goal > 0 ? count1(nums, goal) - count1(nums, goal - 1) : count1(nums, 0);
}