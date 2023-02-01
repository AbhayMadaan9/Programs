#include<bits/stdc++.h>
using namespace std;
//This problem can be solved using similiar logic of koko eating bananas
//https://www.codingninjas.com/codestudio/problems/smallest-divisor-with-the-given-limit_1755882?leftPanelTab=1
#include <bits/stdc++.h> 
int smallestDivisor(vector<int>& arr, int n, int limit) 
{
    int max_divisor = *max_element(arr.begin(), arr.end());
        //base case
    if(limit == arr.size()) return max_divisor;
    //binary search for the getting the min. integer
    int l = 1, h = max_divisor, mid;
    while(l <= h){
        mid = l + (h-l)/2;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += ceil(arr[i]*1.0/mid);
        }
        if(sum <= limit) {h = mid-1;}    
        else l = mid+1; 
    }
    return l;
}
int main()
{
    return 0;
}