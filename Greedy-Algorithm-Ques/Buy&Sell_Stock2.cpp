//https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell_696432?leftPanelTab=0
//Since we can make any number of transaction(when we buy a stock we can buy another stock only after selling the prev. stock)
//we will create multiple cases of buying and selling the stocks through recursion. and attain the maximum profit from it
//For each stock we have check wheather the stock is bought or not for which we keep a bool parameter bought and on further we have two choices wheather to buy/sell/skip the stock
#include<bits/stdc++.h>
int solve(bool bought, int index, int prices[], int n, vector<vector<int>> &dp)
{
    if(index == n) return 0;
    if(dp[index][bought] != -1) return dp[index][bought];
    int profit = 0;
    if(bought)  //means the stock is already bought so we have two choices wheather to sell it or skip it
    {
        int sell = prices[index] + solve(false, index+1, prices, n, dp);
        int skip = 0 + solve(true, index+1, prices,n, dp);
        profit = profit + max(sell, skip);
    }
    else     //means the stock is not bought so we have two choices wheather to buy it or skip it
    {
        int buy = -prices[index] + solve(true, index+1, prices,n, dp);
        int skip = 0 + solve(false, index+1, prices,n, dp);
        profit = profit + max(buy, skip);
    }
    return dp[index][bought] = profit;
}
int maxProfit(int prices[], int n)
{
    
    vector<vector<int>> dp(n, vector<int>(2, -1));  //since we have two changing paramerters- index, bought.
    return solve(false, 0, prices,n, dp);
}