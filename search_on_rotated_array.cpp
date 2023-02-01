#include<bits/stdc++.h>
using namespace std;
//logic is to find the peak element of array then check if key is greater or leass than peek then we apply binary search on that half
//But this is very lengthly approch so another approch is to apply simple binary search with some of the conditions
    //more detail on copy
//https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_630450
int binary_search(int *arr, int l, int r, int key)
{
    if(l > r) return -1;
    int mid = l + (r-l)/2;
    if(arr[mid] == key) return mid;
    //check if left half is sorted
    if(arr[l] <= arr[mid])
    {
        //check if element is present in left half
        if(key >= arr[l] && key <= arr[mid])
        {
            return binary_search(arr, l, mid-1, key);
        }
        //if not go to right half
        else return binary_search(arr, mid+1, r, key);
    }
    //check if right half is sorted
    if(arr[r] >= arr[mid])
    {
        //check if element is present in right half
        if(key <= arr[r] && key >= arr[mid])
        {
            return binary_search(arr, mid+1, r, key);
        }
        else return binary_search(arr, l, mid-1, key);
    }
else return -1;
}
int search(int* arr, int n, int key) {
    return binary_search(arr, 0, n-1, key);
}
int main()
{
    return 0;
}