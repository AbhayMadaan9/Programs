#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698?leftPanelTab=1
//https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell_696432?leftPanelTab=0
//Since we can make any number of transaction(when we buy a stock we can buy another stock only after selling the prev. stock)
//we will create multiple cases of buying and selling the stocks through recursion. and attain the maximum profit from it
//For each stock we have check wheather the stock is bought or not for which we keep a bool parameter bought and on further we have two choices wheather to buy/sell/skip the stock
#include<bits/stdc++.h>
int solve(bool bought, int index, vector<int> &prices, int n, vector<vector<vector<int>>> &dp, int limit)
{
    if(index == n) return 0;
    if(dp[index][bought][limit] != -1) return dp[index][bought][limit];
    if(limit == 0) return 0;
    int profit = 0;
    if(bought)  //means the stock is already bought so we have two choices wheather to sell it or skip it
    {
        int sell = prices[index] + solve(false, index+1, prices, n, dp, limit-1);
        int skip = 0 + solve(true, index+1, prices,n, dp, limit);
        profit = profit + max(sell, skip);
    }
    else     //means the stock is not bought so we have two choices wheather to buy it or skip it
    {
        int buy = -prices[index] + solve(true, index+1, prices,n, dp,limit);
        int skip = 0 + solve(false, index+1, prices,n, dp, limit);
        profit = profit + max(buy, skip);
    }
    return dp[index][bought][limit] = profit;
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));  //since we have three changing paramerters- index, boughtm, limit.
    return solve(false, 0, prices,n, dp, k);
}