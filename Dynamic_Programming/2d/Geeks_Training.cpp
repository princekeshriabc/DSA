// Geek's Training
// https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training
// time complexity =O(4*N)
// space complexity =O(4*N) for space optimize code O(4) 

// memoization code
int help(int day,int last,vector<vector<int>>& points,vector<vector<int>>& dp){
    if(day==0){
        int maxi=INT_MIN;
        for(int i=0;i<=2;i++){
            if(i!=last)
            maxi=max(maxi,points[0][i]);
        }
        return maxi;
    }
    if(dp[day][last]!=-1){
        return dp[day][last];
    }
    for(int task=0;task<=2;task++){
        if(task!=last){
            int point=points[day][task]+help(day-1,task,points,dp);
            dp[day][last]=max(dp[day][last],point);
        }
    }
    return dp[day][last];
}
int maximumPoints(vector<vector<int>>& points, int n) {
    // Code here
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return help(n-1,3,points,dp);
}

// space optimation code
int maximumPoints(vector<vector<int>> &points, int n)
{
    // Code here
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][2], points[0][0]);
    prev[2] = max(points[0][1], points[0][0]);
    prev[3] = max(points[0][1], max(points[0][0], points[0][2]));
    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            // temp[last]=0;
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}