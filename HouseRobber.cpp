#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/house-robber_6211018?leftPanelTab=1
//similir to Maximum sum of non-adjacent elements but here's special case is the last and first house is connected
//logic is we either we include first or exclude first
int solveRec(int n, vector<int> &nums)
{
    if(n<0) return 0;
    if(n==0) return nums[0];

    int incl = solveRec(n-2, nums) + nums[n];
    int exl = solveRec(n-1, nums) + 0;
    return max(incl, exl);
}
int solveMem(int n, vector<int> &nums, vector<int>&dp)
{
    if(n<0) return 0;
    if(n==0) return nums[0];
    if(dp[n] != -1) return dp[n];
    int incl = solveMem(n-2, nums, dp) + nums[n];
    int exl = solveMem(n-1, nums, dp) + 0;
    return dp[n] = max(incl, exl);
}
int solveTab(int n, vector<int> &nums)
{
    vector<int>dp(nums.size(), -1);
    if(n<0) return 0;
    if(n==0) return nums[0];
    dp[0] = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        int incl = dp[i-2] + nums[i];
        int exl = dp[i-1] + 0;
        dp[i] = max(incl, exl);
    }
    return dp[nums.size()-1];
}

int houseRobber(vector<int>&a) {
    int n = a.size();
    vector<int>IncFirst;
    vector<int>IncLast;
    vector<int>dp(n+1, -1);
    for(int i = 0; i < n; i++)
    {
        if(n != 0) IncLast.push_back(a[i]);
        if(n != n-1) IncFirst.push_back(a[i]);
    }
    
    return max(solveTab(n-1, IncFirst), solveTab(n-1, IncLast));
}

