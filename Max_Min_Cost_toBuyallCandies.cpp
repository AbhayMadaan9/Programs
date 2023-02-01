#include<bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/minimum-and-maximum-cost-to-buy-n-candies_975298?leftPanelTab=1
// Function to calculate minimum cost.
long long minimumCost(vector<int> &cost, int n, int k)
{
    long long mini = 0;
    sort(cost.begin(), cost.end());
    int i = 0, j = n-1;
    while(i <= j)
    {
        mini += cost[i];
         j -= k;
        i++;
    }
    return mini;
}

// Function to calculate maximum cost.
long long maximumCost(vector<int> &cost, int n, int k)
{
        long long maxi = 0;
    sort(cost.begin(), cost.end(), greater<int>());
    int i = 0, j = n-1;
    while(i <= j)
    {
        maxi += cost[i];
         j -= k;
        i++;
    }
    return maxi;
}