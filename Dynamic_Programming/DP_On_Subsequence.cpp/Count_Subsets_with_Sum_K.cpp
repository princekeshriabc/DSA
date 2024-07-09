// Count Subsets with Sum K
// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem
// time complexity =O(n*sum)
// space complexity =O(n*sum) +O(n)


class Solution
{

public:
    int help(int ind, int sum, vector<int> &ar, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (sum == 0 && ar[0] != 0)
                return 1;
            if (sum == 0 && ar[0] == 0)
                return 2;
            return (ar[0] == sum);
        }
        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        int notpick = help(ind - 1, sum, ar, dp);
        int pick = 0;
        if (ar[ind] <= sum)
        {
            pick = help(ind - 1, sum - ar[ind], ar, dp);
        }
        return dp[ind][sum] = (pick + notpick) % 1000000007;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<int> ar(arr, arr + n);
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return help(n - 1, sum, ar, dp);
    }
};