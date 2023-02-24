#include<bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397?leftPanelTab=0
int findDuplicate(vector<int> &arr) 
{
    //approch1
    // unordered_map<int, int>ump;
    // for(auto i: arr)
    // {
    //     ump[i]++;
    // }	
    // for(auto i: ump)
    // {
    //     int freq = i.second;
    //     if(freq > 1) return i.first;
    // }
    // return -1;
    //approch 2
    //sort(arr.begin(), arr.end());
    //approch 3
    // use frequency array 
    //approch 4(from striver slow and fast pointer)
    int slow = arr[0];
int fast = arr[0];
do {
     slow = arr[slow]; //one step
     fast = arr[arr[fast]]; //two step
 } while(fast!=slow);
   fast = arr[0];
while(slow != fast) {
     slow = arr[slow];
     fast = arr[fast];
}
 return slow;

}
