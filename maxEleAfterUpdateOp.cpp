#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/find-the-maximum-element-in-the-array-after-update-operations_1214621?leftPanelTab=0
int findMaxElement(vector < pair < int, int > > & arr, int n, int m) {
    vector<int>A(n, 0);
    for(auto &Ranges: arr)
    {
        auto range = Ranges;
        int ind1 = Ranges.first-1;
        int ind2 = Ranges.second-1;
        for(int i = ind1; i <= ind2; i++)
        {
            A[i]++;
        }
    }    
    return *max_element(A.begin(), A.end());
}