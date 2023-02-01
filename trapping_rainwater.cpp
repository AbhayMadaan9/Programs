#include<bits/stdc++.h>
using namespace std;
//approch on copy
//https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
  //prefix max array
int * prefix_max(int arr[], int n)
{
    int *ans = new int[n];
    int maxi = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
        }
        ans[i] = maxi;
    }
    return ans;
}
//prefix max array
int * suffix_max(int arr[], int n)
{
    int *ans = new int[n];
    int maxi = arr[n-1];
    for(int i = n-1; i >= 0; i--)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
        }
        ans[i] = maxi;
    }
    return ans;
}
    long long trappingWater(int arr[], int n){
        // code here
            long trapped_water = 0;
    int* left = prefix_max(arr, n);
    int* right = suffix_max(arr, n);
    for(int i = 0; i < n; i++)
    {
        trapped_water += min(left[i], right[i]) - arr[i];
    }
    return trapped_water;
    }
    //compressed 
long getTrappedWater(long *arr, int n){
       long *lmax = new long[n];
       long *rmax = new long[n];
    //prefix max
       lmax[0] = arr[0];
       for(int i=1;i<n;i++){
           lmax[i] = max(arr[i],lmax[i-1]);
       }
    //suffix max
       rmax[n-1] = arr[n-1];
       for(int i=n-2;i>=0;i--)
           rmax[i] = max(arr[i],rmax[i+1]);
    
       long countTrap = 0;
       for(int i=0;i<n;i++)
       countTrap += min(rmax[i],lmax[i])-arr[i];
   return countTrap;
}
int main()
{
    return 0;
}