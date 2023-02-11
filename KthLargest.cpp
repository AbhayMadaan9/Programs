#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/kth-largest-element_796007?leftPanelTab=1
 int findKthLargest(vector<int>& input, int k) {

    if(k> input.size()) return -1;
    priority_queue<int>q;
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