#include<bits/stdc++.h>
using namespace std;
//Approch is for the first occurence element when we find it in mid we make end = mid-1 and continue till possible so that we get the lasted founded in the leftmost side similiat for the last occurence element
//https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?leftPanelTab=1
int first_occurence(vector<int>& arr, int n, int k){
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

int last_occurence(vector<int>& arr, int n , int k){
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
    pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
   pair<int, int>ans;
        ans.first = first_occurence(arr, n, k);
        ans.second = last_occurence(arr, n, k);
        return ans;
}
int main()
{
    return 0;
}