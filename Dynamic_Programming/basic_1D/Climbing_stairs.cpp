// climbing stairs problem
// https://leetcode.com/problems/climbing-stairs/solutions/5402109/simple-solution-in-o-1-space-and-memoization-also/
// time complexity= O(n)
// space complexity= O(n) for memoization solution
// space complexity= O(1) for O(1) space solution

// memoization solution
int help(int n,vector<int>& dp){
    if(n==0||n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=help(n-1,dp)+help(n-2,dp);
}
int climbStairs(int n) {

    vector<int> dp(n+1,-1);
    return help(n,dp);
}

// O(1) space solution
int climbStairs(int n)
{

    int prev = 1, prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
}
;