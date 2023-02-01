#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/fractional-knapsack_975286?leftPanelTab=1
static bool compare(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.second/a.first;
    double r2 = (double)b.second/b.first;
    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    double profit = 0.0;
    sort(items.begin(), items.end(), compare);
    for(int i = 0; i < n; i++)
    {
        if(items[i].first <= w){
            w -= items[i].first;
            profit += items[i].second;
        }
        else
        {
            profit += w * (double)items[i].second/items[i].first;
            break;
        }
    }
    return profit;
}