#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/occurrence-of-x-in-a-sorted-array_630456?leftPanelTab=1
int first_occurence(int arr[], int n, int k){
    int s = 0, e = n-1;
    int mid = s + (e-s) / 2;
    int ans = -1;
    while(s<=e){
        if (arr[mid] == k){
            ans = mid;
            e = mid - 1;
        }
        else if(k>arr[mid]){
            s = mid + 1;
        }
        else if(k<arr[mid]){
            e = mid - 1;
        }
        mid = s + (e-s) / 2;
    }
    return ans;
}

int last_occurence(int arr[], int n , int k){
    int s = 0, e = n-1;
    int mid = s + (e-s) / 2;
    int ans = -1;
    while(s<=e){
        if (arr[mid] == k){
            ans = mid;
            s = mid + 1;
        }
        else if(k>arr[mid]){
            s = mid + 1;
        }
        else if(k<arr[mid]){
            e = mid - 1;
        }
        mid = s + (e-s) / 2;
    }
    return ans;   
}
int countOccurences(int arr[], int n, int X)
{
    //logic is to find the index of first and last occurence of X and find the size
    if(last_occurence(arr, n, X) == -1 or first_occurence(arr, n, X) == -1) return 0;
    return  last_occurence(arr, n, X)-first_occurence(arr, n, X) + 1;int s = 0;
}
int main()
{
    return 0;
}