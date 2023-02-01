#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=1
//approch on copy
int Recursive(int n, vector<int> &heights)
{
    //base case
    if(n==0) return 0;
    
    int OneJump = Recursive(n-1, heights) + (abs(heights[n-1] - heights[n]))%100000007;
    int TwoJump = INT_MAX;
    if(n > 1) TwoJump = Recursive(n-2, heights) + (abs(heights[n-2] - heights[n]))%100000007;
    return min(OneJump, TwoJump);
    
}
int Memoization(int n, vector<int> &heights, vector<int> &dp)
{
    //base case
    if(n==0) return 0;
    if(dp[n] != -1) return dp[n];
    
    int OneJump = Recursive(n-1, heights) + (abs(heights[n-1] - heights[n]))%100000007;
    int TwoJump = INT_MAX;
    if(n > 1) TwoJump = Recursive(n-2, heights) + (abs(heights[n-2] - heights[n]))%100000007;
    return dp[n] = min(OneJump, TwoJump);
}
int Tabulation(int n, vector<int> &height)
{
vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
    return dp[n-1];
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1, -1);
    return Tabulation(n, heights);
}