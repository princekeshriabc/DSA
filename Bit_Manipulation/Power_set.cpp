// using bit manipulation we find the all subset of the array

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> v;
    vector<int> a;
    int n = 1 << nums.size();
    for (int i = 0; i < n; i++)
    {
        vector<int> a;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i & (1 << j) == 1)
            {
                a.push_back(nums[j]);
            }
        }
        v.push_back(a);
    }
    return v;
}