//https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell_696432?leftPanelTab=0
//https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969?leftPanelTab=0
//Since we can make any number of transaction(when we buy a stock we can buy another stock only after selling the prev. stock)
//we will create multiple cases of buying and selling the stocks through recursion. and attain the maximum profit from it
//For each stock we have check wheather the stock is bought or not for which we keep a bool parameter bought and on further we have two choices wheather to buy/sell/skip the stock
#include<bits/stdc++.h>
int getAns(vector<int> Arr, int ind, int buy, int n, vector<vector<int>> &dp ){

    if(ind>=n) return 0; //base case
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    int profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,ind+1,0,n,dp), -Arr[ind]+getAns(Arr,ind+1,1,n,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,ind+1,1,n,dp), Arr[ind]+getAns(Arr,ind+2,0,n,dp));
    }
    
    return dp[ind][buy] = profit;
}


int stockProfit(vector<int> &Arr)
{
    int n = Arr.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    
    int ans = getAns(Arr,0,0,n,dp);
    return ans;
}

