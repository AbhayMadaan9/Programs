#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/find-the-nearest-supporter_1082335
vector<int> prevSmall(vector<int> arr, int n) {
    stack<int>st;
    vector<int>Suppporters(n, -1);
    
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() and st.top() >= arr[i])
        {
            st.pop();
        }
        if(!st.empty()) Suppporters[i] = st.top();
        st.push(arr[i]);
    }
    return Suppporters;
}
