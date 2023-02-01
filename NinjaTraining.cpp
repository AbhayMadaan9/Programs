//logic on copy
int solveRec(vector<vector<int>> &points, int day, int last)
{
    if(day == 0) 
    {
        int maxi = 0;
        for(int i = 0; i < points[0].size(); i++)
        {
            if(last != i) maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    int maxi = 0;
    for(int i = 0; i < points[day].size(); i++)
    {
        if(last != i){ int point = points[day][i] + solveRec(points, day-1, i);
        maxi = max(maxi, point);}
    }
    return maxi;
}
int solveMem(vector<vector<int>> &points, int day, int last, vector<vector<int>>&dp)
{
    if(day == 0) 
    {
        int maxi = 0;
        for(int i = 0; i < points[0].size(); i++)
        {
            if(last != i) maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if(dp[day][last] != -1) return dp[day][last];
    int maxi = 0;
    for(int i = 0; i < points[day].size(); i++)
    {
        if(last != i){ int point = points[day][i] + solveMem(points, day-1, i, dp);
        maxi = max(maxi, point);}
    }
    return dp[day][last]= maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
   // return solveRec(points, n-1, -1);
    vector<vector<int>>dp(n, vector<int>(4, -1));
    //didn't get last initially it should be anything but not 0,1,2 since initially we have to take all but here's on taking only 3 it runs why??
    return solveMem(points, n-1,3, dp);
}