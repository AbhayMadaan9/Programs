//https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_1063255?leftPanelTab=1

//we will be comparing two strings if any character doesn't matches then we have two choices wheather to increment string 1 character or string 2 character 
#include <bits/stdc++.h>
int solve(string & str1, string & str2, int n1, int n2, vector<vector<int>>&dp)
{
   
    if(n1 == str1.size() || n2 == str2.size()) return 0;  //completly traversed
    if(dp[n1][n2] != -1) return dp[n1][n2];
    int ans = 0;
    if(str1[n1] == str2[n2]) ans = solve(str1, str2, n1+1, n2+1,dp) + 1;
    if(str1[n1] != str2[n2]) 
    {
         ans =  max(solve(str1, str2, n1+1, n2,dp), solve(str1, str2, n1, n2+1,dp));
    }
    return dp[n1][n2] = ans;
}
int getLengthOfLCS(string & str1, string & str2) {
    
    int n1 = str1.length();
    int n2 = str2.length();
   vector<vector<int>>dp(n1,vector<int>(n2,-1));
    return solve(str1, str2, 0, 0, dp);
}