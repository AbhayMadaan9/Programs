//This solve will find the subset whose sum is equal to target
//https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?leftPanelTab=1
//same as subset sum problem
bool solve(vector<int> arr, int n, int index, int target, int sum, vector<vector<int>> &dp)
{
    if(index > n) return false;
    if(sum == target) return true;
     if(sum > target) return false;
    
    //retreving the data from dp table to avoid repetetion of recursion subtree
    if(dp[index][sum] != -1) return dp[index][sum]; 
    
    //Taking the index element to the subset
  bool take =  solve(arr, n, index+1, target, sum+arr[index], dp);

    //Not taking the index element to the  subset
    bool not_take = solve(arr, n, index+1, target, sum, dp);
    
    return dp[index][target] = take or not_take;
    
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

bool canPartition(vector<int> &arr, int n)
{
   
    long int sum = 0; 
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    if(sum%2 != 0)  //checking if sum is even or odd If its odd then it is not possibe to form two subset of equal sum 
    {
        return false;
    }
    else
    {
       int target  = sum/2;
        vector<vector<int>> dp(n, vector<int>(target + 1,-1));
        return solveTab(n,target, arr);
    }
}
