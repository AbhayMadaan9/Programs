#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/rotated-array_1093219?leftPanelTab=1
int binary_search(int *arr, int l, int r)
{
    if(l == r) return arr[l];
    if(l > r) return arr[0];
    int mid = l + (r-l)/2;
       if (mid < r && arr[mid + 1] < arr[mid]) {
           return arr[mid + 1];
       }
    if (mid > l && arr[mid - 1] > arr[mid]) {
           return arr[mid];
    }
    //check if it is present in left half
    if(arr[r] > arr[mid]) return binary_search(arr, l, mid-1);
    else return binary_search(arr, mid+1, r);
    
}

int rotatedArray(int arr[], int n)
{
    return binary_search(arr, 0, n-1);
}
int main()
{
    return 0;
}