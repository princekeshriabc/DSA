// TC = O(N)  SC=O(1) with two pointer and sliding window

int sub(vector<int> &nums, int k)
{
    int l = 0, r = 0, sum = 0, count = 0;
    while (r < nums.size())
    {
        sum += nums[r] % 2;   // relate with binary subarray with sum
        while (sum > k)
        {
            sum -= nums[l] % 2;
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;
    return k > 0 ? sub(nums, k) - sub(nums, k - 1) : sub(nums, 0);
}