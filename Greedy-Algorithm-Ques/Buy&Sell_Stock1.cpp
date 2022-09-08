https://www.codingninjas.com/codestudio/problems/893405?leftPanelTab=1

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
        int profit = 0;
    int minprice = prices[0];
    for(int i = 1; i < prices.size(); i++)
    {
        int diff = prices[i] - minprice;
        minprice = min(minprice, prices[i]);
        profit = max(profit, diff);
    }
    return profit;
}