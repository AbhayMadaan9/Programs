//https://www.codingninjas.com/codestudio/problems/edit-distance_630420?leftPanelTab=1
//approch on copy
#include<bits/stdc++.h>
int solveTab(string s, string t)
{
    int m = s.length();
    int n = t.length();
    vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
    for(int i=0;i<m;i++)dp[i][0]=i;
    for(int j=0;j<n;j++)dp[0][j]=j;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            char a = s[i-1];
            char b = t[j-1];
            if(a==b){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
            }
        }
    }
    return dp[m][n];
    
}
int solveRec(string str1, string str2, int ind1, int ind2)
{
    if(ind1 < 0) return ind2+1;
    if(ind2 < 0) return ind1+1;

    if(str1[ind1] == str2[ind2]) return solveRec(str1, str2, ind1-1, ind2-1);
    else return 1+min(solveRec(str1, str2, ind1-1, ind2), min(solveRec(str1, str2, ind1-1, ind2-1), solveRec(str1, str2, ind1, ind2-1)));
}
int solveMem(string str1, string str2, int ind1, int ind2, vector<vector<int>>&dp)
{
    if(ind1 < 0) return dp[ind1][ind2] = ind2+1;
    if(ind2 < 0) return dp[ind1][ind2] = ind1+1;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(str1[ind1] == str2[ind2]) return dp[ind1][ind2] = solveMem(str1, str2, ind1-1, ind2-1 ,dp);
    else return dp[ind1][ind2] = 1+min(solveMem(str1, str2, ind1-1, ind2, dp), min(solveMem(str1, str2, ind1-1, ind2-1, dp), solveMem(str1, str2, ind1, ind2-1, dp)));
}

int editDistance(string str1, string str2)
{ 
    int size1 = str1.length();
    int size2 = str2.length();
    vector<vector<int>>dp(size1+1, vector<int>(size2+1, 0));
    
        int ans = solveTab(str1, str2);
    return ans;
}