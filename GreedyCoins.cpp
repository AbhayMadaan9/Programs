#include<bits/stdc++.h>
//such particular coins are used so that we can use greedy mehtod to sum up to v 
//https://www.codingninjas.com/codestudio/problems/greedy-algorithm-for-ninja-and-the-coins_3191489?leftPanelTab=1
int minimumCoins(int v) {
    //base case
    if(v==0) return 0;
    if(v==1) return 1;
    
    int total_coins = 0;
    vector<int>arr = {1,2,5,10,20,50,100,500,1000};
    for(int i = 8; i >= 0; i--)
    {
        while(arr[i] <= v) //since we have unlimited coins so we can use while instead of 'if'
        {
            v -= arr[i]; total_coins++;
        }
        
    }
    return total_coins;
}
