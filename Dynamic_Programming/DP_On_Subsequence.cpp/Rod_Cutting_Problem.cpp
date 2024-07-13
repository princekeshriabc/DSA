// Rod Cutting Problem
// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// time complexity = O(n*n)
// space complexity = O(n*n)

// memoization solution
int help(int ind, int n, int price[], vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return n * price[0];
    }
    if (dp[ind][n] != -1)
        return dp[ind][n];
    int notpick = help(ind - 1, n, price, dp);
    int pick = INT_MIN;
    int rodlen = ind + 1;
    if (n >= rodlen)
    {
        pick = price[ind] + help(ind, n - rodlen, price, dp);
    }
    return dp[ind][n] = max(pick, notpick);
}
int cutRod(int price[], int n)
{
    // code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return help(n - 1, n, price, dp);
}

// recurssion solution
int help(int ind,int n,int price[]){
    if(ind==0){
        return n*price[0];
    }
    int notpick=help(ind-1,n,price);
    int pick=INT_MIN;
    int rodlen=ind+1;
    if(n>=rodlen){
        pick=price[ind]+help(ind,n-rodlen,price);
    }
    return max(pick,notpick);
}
int cutRod(int price[], int n)
{
    // code here
    return help(n - 1, n, price);
}