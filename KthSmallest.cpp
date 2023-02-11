#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/kth-smallest-element_893056?leftPanelTab=1
//logic1: sort the array
//logic2:Use min heap and pop till k
int kthSmallest(vector<int> input, int k)
{
    if(k> input.size()) return -1;
    priority_queue<int, vector<int>, greater<int>>q;
    for(int i = 0; i < input.size(); i++)
    {
        q.push(input[i]);
    }
    while(true)
    {
        if(k -=1){
            q.pop();
        }
        else break;
        
    }
    return q.top();
}