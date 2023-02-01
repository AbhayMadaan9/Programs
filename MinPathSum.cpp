
#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?topList=top-dynamic-programming-questions&leftPanelTab=1
int solveRec(vector<vector<int>> &grid, int n, int m)
{
    if(n == 0 and m == 0) return grid[0][0];
    if(n < 0 or m < 0) return 1e9;
    int left = solveRec(grid, n, m-1) + grid[n][m];
    int up = solveRec(grid, n-1, m) + grid[n][m];
    return min(left,up); 
}
int solveMem(vector<vector<int>> &grid, int n, int m, vector<vector<int>>&dp)
{
    if(n == 0 and m == 0) return grid[0][0];
    if(n < 0 or m < 0) return 1e9;
    if(dp[n][m] != -1) return dp[n][m];
    int left = solveRec(grid, n, m-1) + grid[n][m];
    int up = solveRec(grid, n-1, m) + grid[n][m];
    return  dp[n][m] = min(left,up); 
}
int solveTab(int n, int m, vector<vector<int> > &matrix){
    vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = matrix[i][j];
            else{
                
                int up= matrix[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left= matrix[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[n-1][m-1];
    
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

   // return solveRec(grid, n-1, m-1);
    vector<vector<int>>dp(n, vector<int>(m, -1));
    //return solveMem(grid, n-1, m-1, dp);
    return solveTab(n, m, grid);
}