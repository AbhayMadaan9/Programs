#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/minimum-swaps-to-bring-all-elements-less-than-or-equal-to-k-together_1112657?leftPanelTab=1
int minimumSwaps(vector<int> &arr, int n, int k)
{
		// Write your code here
    int count = 0;
    for(auto it: arr){
        if(it<=k) count++;
    }
    
    if(count==n) return 0;
    
    int ans = 0;
    int bad = 0;
    
    for(int i = 0; i<count; i++){
        if(arr[i]>k) bad++;
    }
   
    ans = bad;
    
    for(int i = count, j=0; i<n && j<n; i++,j++){
        if(arr[j]>k) bad--;
        
        if(arr[i]>k) bad++;
        
        ans = min(ans,bad);
    }
    return ans;
}
