#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?leftPanelTab=1
int countPaths(vector<vector<int>>&dp, int m, int n, vector< vector< int> > &mat)
{
    if(m<1 || n<1)
    {
        return 0;
    }
    if(mat[m-1][n-1]==-1)
    {
        return 0;
    }
    if(m==1 &&   n==1)
    {
        return 1;
    }
    if(dp[m][n]!=-1)
    {
        return dp[m][n]%1000000007;
    }
    
    return dp[m][n]=(countPaths(dp,m-1,n,mat)+countPaths(dp,m,n-1,mat))%1000000007;
}



int mazeObstacles(int m, int n, vector< vector< int> > &mat) {
    // Write your code here
     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return countPaths(dp,m,n,mat);
}