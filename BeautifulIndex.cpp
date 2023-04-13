#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/beautiful-index_3743983?leftPanelTab=1
int beautifulIndex(int n, vector<int> a)
{
    // get prefix array
    vector<int> prefix(n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        prefix[i] = sum;
        sum += a[i];
    }
    // get suffix array
    vector<int> suffix(n);
    sum = 0;
    for(int i = n-1; i >= 0; i--)
    {
        suffix[i] = sum;
        sum += a[i];
    }

    // find the index
    for(int i = 0; i < n; i++)
    {
        if(prefix[i] == suffix[i]) return i+1;
    }
    return -1;
}
