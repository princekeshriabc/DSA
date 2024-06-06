// TC = O(n) SC = O(1)
// this solution is (<=k)-(<=k-1)

int solve(vector<int> &nums, int k)
{
    int l = 0, r = 0, count = 0, d = 0;
    unordered_map<int, int> mp;
    while (r < nums.size())
    {
        mp[nums[r]]++;
        while (mp.size() > k)
        {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0)
                mp.erase(nums[l]);
            l++;
        }
        count += r - l + 1;
        r++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return k > 0 ? solve(nums, k) - solve(nums, k - 1) : solve(nums, 0);
}