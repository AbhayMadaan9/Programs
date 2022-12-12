#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813?leftPanelTab=1
int bestInsertPos(vector<int> arr, int n, int m)
{
    int best_pos = -1;
    int start = 0, end = n-1; 
    
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(arr[mid] == m) return mid;
        else if(arr[mid] > m) {end = mid-1; best_pos = mid;}
        else start = mid+1;
    }
    if(best_pos == -1)return n;
    else return best_pos;
}
int main()
{
    return 0;
}