#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?leftPanelTab=0
int solveRec(int m, int n)
{
	if(n == 0 and m == 0) return 1;
	if(n < 0 or m < 0) return 0;

	int right = solveRec(m-1, n);
	int down = solveRec(m, n-1);
	return right + down;
}
int solveMem(int m, int n, vector<vector<int>>&dp)
{
	if(n == 0 and m == 0) return 1;
	if(n < 0 or m < 0) return 0;

	if(dp[n][m] != -1) return dp[n][m];
	int right = solveRec(m-1, n);
	int down = solveRec(m, n-1);
	return dp[n][m] = right + down;
}
int solveTab(int m, int n)
{
	vector<vector<int>>dp(m, vector<int>(n, -1));

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
		{
			if(n == 0 and m == 0) {dp[0][0] = 1; continue;}
			else{
				 int right = i>0? dp[i-1][j]: 0;
				int down = j>0? dp[i][j-1]:0;
				dp[i][j] = right+down;
			}
		}
	}
	return dp[n][m];
}
int uniquePaths(int m, int n) {
//	return solveRec(m-1, n-1);
	vector<vector<int>>dp(n, vector<int>(m, -1));
	 return solveMem(m-1, n-1, dp);
	 //solveTab not working
	//return solveTab(m, n);
}