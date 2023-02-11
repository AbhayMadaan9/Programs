//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459
//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-increasing-subsequence-1587115620
//logic is we will be either taking or not taking the ele. and we maintain the prev. taken ele. inorder to compare while taking the curr. ele. in order to maintain logest increasing subsequence.
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solveRec(int arr[], int n, int curInd, int PrevInd)
{
    if(curInd == n) {
    if(arr[PrevInd] < arr[curInd]) return 1;
    else return 0;    
    }
     int len = solveRec(arr, n, curInd+1, PrevInd);
   // int Take = INT_MIN;
    if(arr[PrevInd] < arr[curInd] or PrevInd == -1)
    {
    len = max(len, 1+solveRec(arr, n, curInd+1, curInd));
    } 
    return len;
}
int solveMem(int arr[], int n, int curInd, int PrevInd, vector<vector<int>>&dp)
{
    if(curInd == n) {
    if(arr[PrevInd] < arr[curInd]) return dp[curInd][PrevInd+1] = 1;
    else return dp[curInd][PrevInd+1] = 0;    
    }
    if(dp[curInd][PrevInd+1] != -1) return dp[curInd][PrevInd+1];
     int len = solveMem(arr, n, curInd+1, PrevInd, dp);
   // int Take = INT_MIN;
    if(arr[PrevInd] < arr[curInd] or PrevInd == -1)
    {
    len = max(len, 1+solveMem(arr, n, curInd+1, curInd, dp));
    } 
    return dp[curInd][PrevInd+1] = len;
}
    int longestSubsequence(int n, int arr[])
    {
vector<vector<int>>dp(n, vector<int>(n+1, -1));
    return solveMem(arr, n-1, 0, -1, dp);    
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends