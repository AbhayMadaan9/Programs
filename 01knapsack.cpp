#include <bits/stdc++.h>
// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_1072980?leftPanelTab=1
int solveRec(int ind, vector<int> &values, vector<int> &weights, int w)
{
	if(ind == 0) 
	{
		if(weights[ind] <= w) return values[ind];
		 else return 0;
	}
	int inc = INT_MIN;
	if(w >= weights[ind]){
	inc = solveRec(ind-1, values, weights, w-weights[ind]) + values[ind];}
	int exc = solveRec(ind-1, values, weights, w);
	return max(inc, exc);
}
int solveMem(int ind, vector<int> &values, vector<int> &weights, int w, vector<vector<int>>&dp)
{
	if(ind == 0) 
	{
		if(weights[ind] <= w) return values[ind];
		 else return 0;
	}
	if(dp[ind][w] != -1) return dp[ind][w];
	int inc = INT_MIN;
	if(w >= weights[ind]){
	inc = solveMem(ind-1, values, weights, w-weights[ind], dp) + values[ind];}
	int exc = solveMem(ind-1, values, weights, w, dp);
	return dp[ind][w] = max(inc, exc);
}
int solveTab(int n, vector<int> &values, vector<int> &weights, int w)
{
	vector<vector<int>>dp(n, vector<int>(w+1, 0));
	//base case (for singe ele.)
	for(int i = weights[0]; i <= w; i++)
	{
		if(weights[0] <= w) dp[0][i] = values[0];
		else dp[0][i] = 0;
	} 

	for(int ind = 1; ind < n; ind++)
	{
		for(int W = 0; W <= w; W++)
		{
			int inc = INT_MIN;
			if(W >= weights[ind]){
			inc = dp[ind-1][W-weights[ind]] + values[ind];}
			int exc = dp[ind-1][W];
			dp[ind][W] = max(inc, exc);
		}
	}
	return dp[n-1][w];

}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// return solveRec(n-1, values, weights, w);
	vector<vector<int>>dp(n, vector<int>(w+1, -1));
	//return solveMem(n-1, values, weights, w, dp);
	return solveTab(n, values, weights, w);
}