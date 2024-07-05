// Subset Sum Problem
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// time complexity = O(n*sum)
// space complexity = O(n*sum) 

bool help(int n, vector<int> &arr, vector<vector<int>> &t, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
    {
        return arr[0] == sum;
    }

    if (t[n][sum] != -1)
        return t[n][sum];
    bool nottake = help(n - 1, arr, t, sum);
    bool take = false;
    if (sum >= arr[n])
    {
        take = help(n - 1, arr, t, sum - arr[n]);
    }

    return t[n][sum] = take || nottake;
}
bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<int>> t(n, vector<int>(sum + 1, -1));
    return help(n - 1, arr, t, sum);
}

//tabulation solution
bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<int>> t(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)
    {
        t[i][0] = true;
    }
    if (arr[0] <= sum)
    {
        t[0][arr[0]] = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool nottake = t[i - 1][j];
            bool take = false;
            if (j >= arr[i])
            {
                take = t[i - 1][j - arr[i]];
            }
            t[i][j] = take || nottake;
        }
    }
    return t[n - 1][sum];
}