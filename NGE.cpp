#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    //brute force approch is to use two loops like for the ith element we traverse from i+1 to n-1 to find first greater element.
    //optimal approch is to start from last to first keep elements on stack to get greater element
   stack<int> s;
    vector<int> nge_list(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            nge_list[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return nge_list;

}