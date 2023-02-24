#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/nth-fibonacci-number_1115780?leftPanelTab=0
int solveRec(int n)
{
    if(n == 0 or n == 1) return n;
    int ans = (solveRec(n-1) + solveRec(n-2))%1000000007;
    return ans;
}

int solveMem(int n, vector<int>&dp)
{
    if(n == 0 or n == 1) return n;
    if(dp[n] != -1) return dp[n];
    int ans = (solveMem(n-1, dp) + solveMem(n-2, dp))%1000000007;
    return dp[n] = ans;
}

int solveTab(int n)
{
    vector<int>dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2])%1000000007;
    }
    return dp[n];
}
int solveSpaceOp(int n)
{
    vector<int>dp(n+1, -1);
    int prev1 = 0;
    int prev2 = 1;

    for (int i = 2; i <= n; i++) {
      int cur = (prev1 + prev2)%1000000007;
      prev1 = prev2;
      prev2 = cur;
    }
    return prev2;
}

int fibonacciNumber(int n){
   // return solveRec(n);
    vector<int>dp(n+1, -1);
    //return solveMem(n, dp);
    //return solveTab(n);
    return solveSpaceOp(n);
}
