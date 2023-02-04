#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/minimum-coins_982764
int solveRec(vector<int>arr, int p, int ind)
{
    if(p==0) return 0;
    if(ind == 0)
    {
        if(p%arr[0] == 0) return p/arr[0];
        else return 1e9;
    }
    int inc = INT_MAX;
    if(p >= arr[ind]) inc = solveRec(arr, p-arr[ind], ind) + 1;
    int exc = solveRec(arr, p, ind-1);
    
    return min(inc,exc); 
}
int solveMem(vector<int>arr, int p, int ind, vector<vector<int>>&dp)
{
    if(p==0) return 0;
    if(ind == 0)
    {
        if(p%arr[0] == 0) return p/arr[0];
        else return 1e9;
    }
    if(dp[ind][p] != -1) return dp[ind][p];
    int inc = INT_MAX;
    if(p >= arr[ind]) inc = solveMem(arr, p-arr[ind], ind, dp) + 1;
    int exc = solveMem(arr, p, ind-1, dp);
    
    return dp[ind][p] = min(inc,exc); 
}
int solveTab(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}
int solveSpaceOp(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<int> prev(T+1,0), cur(T+1,0);
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + cur[target - arr[ind]];
                
             cur[target] = min(notTake, take);
        }
        prev = cur;
    }
    
    int ans = cur[T];
    if(ans >=1e9) return -1;
    return ans;
}
int minimumCoins(int p)
{
     vector<int>arr;
     arr.push_back(1);
     arr.push_back(2);
     arr.push_back(5);
     arr.push_back(10);
     arr.push_back(20);
     arr.push_back(50);
     arr.push_back(100);
     arr.push_back(500);
     arr.push_back(1000);

   // return solveRec(arr, p, 8);
    vector<vector<int>>dp(9, vector<int>(p+1, -1));
   // return solveMem(arr, p, 8, dp);
    //return solveTab(arr, p);
    return solveSpaceOp(arr, p);
}