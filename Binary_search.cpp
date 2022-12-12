#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/binary-search_972?leftPanelTab=1
int solve(int *input, int start, int end, int val){
    if(start > end) return -1;
    int mid = (end+start)/2;
    if(input[mid] == val) return mid;
    else if(input[mid] > val) return solve(input, start, mid-1, val);
    return solve(input, mid+1, end, val);
    
}
int binarySearch(int *input, int n, int val)
{
    return solve(input, 0, n-1, val);
        
}
int main()
{
    return 0;
}