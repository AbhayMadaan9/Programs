//we can take the same coin any number of times to form the given value
#include<bits/stdc++.h>
long solveRec(int denominations[], int n, int value)
{
    if(value == 0) return 1;
    if(n == 0)
    {
        if(value%denominations[0] == 0) return 1; //since we can have infinite supply and it can form target.
        else return 0; 
    }
 
   //taking the coin
    //we can take the same coin any number of times to form the given value
    long int take = 0;
    if(value >= denominations[n]) {
   take =  solveRec(denominations, n, value - denominations[n]);}
    //Not taking the coin
    long int not_take = solveRec(denominations, n-1, value);
    
    return take + not_take;
    
}

long solveMem(int denominations[], int n, int value, vector<vector<int>>&dp)
{
    if(value == 0) return 1;
    if(n == 0)
    {
        if(value%denominations[0] == 0) return 1; //since we can have infinite supply and it can form target.
        else return 0; 
    }
    if(dp[n][value] != -1) return dp[n][value];
   //taking the coin
    //we can take the same coin any number of times to form the given value
    long int take = 0;
    if(value >= denominations[n]) {
   take =  solveMem(denominations, n, value - denominations[n], dp);}
    //Not taking the coin
    long int not_take = solveMem(denominations, n-1, value, dp);
    
    return dp[n][value] = (take + not_take);
    
}
long solveTab(int denominations[], int n, int value)
{
      vector<vector<int>>dp(n, vector<int>(value+1, 0));

     //Initializing base condition
    for(int i=0;i<=value;i++){
        if(i%denominations[0]==0)
            dp[0][i]=1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }

    for(int ind=1; ind<n;ind++){
        for(int target=0;target<=value;target++){
            long notTaken = dp[ind-1][target];
            
            long taken = 0;
            if(denominations[ind]<=target)
                taken = dp[ind][target-denominations[ind]];
                
            dp[ind][target] = notTaken + taken;
        }
    }
    
    return dp[n-1][value];
    
}
long solveSpaceOpt(int denominations[], int n, int value)
{
    vector<int>cur(value+1, 0);
    vector<int>prev(value+1, 0);

     //Initializing base condition
    for(int i=0;i<=value;i++){
        if(i%denominations[0]==0)
            prev[i]=1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }

    for(int ind=1; ind<n;ind++){
        for(int target=0;target<=value;target++){
            long notTaken = prev[target];
            
            long taken = 0;
            if(denominations[ind]<=target)
                taken = cur[target-denominations[ind]];
                
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    
    int ans = cur[value];
    if(ans >=1e9) return -1;
    return ans;
    
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<int>>dp(n, vector<int>(value+1, -1));
    return solveSpaceOpt(denominations, n, value);
}