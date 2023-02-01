#include<bits/stdc++.h>
using namespace std;
//O(Nlog(N)) time complexicity
//https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?leftPanelTab=0


bool ispossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else if(arr[i] > mid) return false;
        else
        {
            studentCount++;
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
    }
    return true;
}


int allocateBooks(vector<int> arr, int n, int m) {
     int low = 0;
    int high;
    int mid;
    for(int i = 0; i < n; i++)
    {
        high += arr[i];
    }

    while(low <= high)
    {
        mid = low + (high- low)/2;
        if(ispossible(arr, n, m, mid))
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return low;
}
int main()
{
    return 0;
}