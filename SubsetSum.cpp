#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/1550954?leftPanelTab=1
bool solveRec(int i, int sum, int n, int k, vector<int> &arr)
{
    if(sum == k) return true;
    if(sum > k || i > n-1) return false;

    int incl = solveRec(i+1, sum+arr[i], n, k, arr);
    int excl = solveRec(i+1, sum, n, k, arr);

    return (incl or excl);
}
bool solveMem(int i, int sum, int n, int k, vector<int> &arr, vector<vector<bool>> &dp)
{
    if(sum == k) return true;
    if(sum > k || i > n-1) return false;
    if(dp[i][sum]) return true;
    int incl = solveMem(i+1, sum+arr[i], n, k, arr, dp);
    int excl = solveMem(i+1, sum, n, k, arr, dp);

    return dp[i][sum] = (incl or excl);
}
bool solveTab(int n, int k, vector<int> &arr)
{
     vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){ //if target is 0 then for any index it is true
        dp[i][0] = true;
    }
    
    if(arr[0]<=k)    //?
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    if(k == 0) return true;
    //return solveRec(0, 0, n, k, arr);
    vector<vector<bool>>dp(n+1, vector<bool>(k+1, false));
    //return solveMem(0, 0, n, k, arr, dp);
    return solveTab(n,k,arr);
}