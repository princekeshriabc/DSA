// Longest Common Substring
// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// time complexity = O(n*m)
// space complexity = O(n*m)  // for tabulation solution
// spce complexity = O(m) for space optimization solution

// tabulation solution
int longestCommonSubstr (string S1, string S2, int n, int m)
{
    // your code here
    int ans=0;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<m+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S1[i-1]==S2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}

// space optimization solution
class Solution
{
public:
    
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // your code here
        int ans = 0;
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int j = 0; j < m + 1; j++)
        {
            prev[j] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return ans;
    }
};