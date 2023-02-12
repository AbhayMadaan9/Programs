#include <bits/stdc++.h> 
class Kthlargest {
    // approch on copy
    //https://www.codingninjas.com/codestudio/problems/kthlargestnumber_800301?topList=striver-sde-sheet-problems&leftPanelTab=1
public:
priority_queue<int, vector<int>, greater<int>>pq;
int size;
    Kthlargest(int k, vector<int> &arr) {
        size = k;
        for(int i = 0; i < arr.size(); i++)
        {
            pq.push(arr[i]);
            if(pq.size() > k) pq.pop();
        }
    }

    void add(int num) {
         pq.push(num);
         if(pq.size() > size) pq.pop();
    }

    int getKthLargest() {
       return pq.top();
    }

};