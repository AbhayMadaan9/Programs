#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/k-most-frequent-elements_3167808?leftPanelTab=1
//approch is to find freq, using hashmap and put it in priority queue and get k max among them
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int, int>ump;
    for(int i = 0; i < n; i++)
    {
        ump[arr[i]]++;
    }
    priority_queue<pair<int, int>>pq;
    unordered_map<int, int>::iterator ite;
    for(auto ite = ump.begin(); ite != ump.end(); ite++)
    {
        pq.push({ite->second, ite->first});
    }
    vector<int>ans;
    while(k--)
    {
        pair<int, int> top = pq.top();
        ans.push_back(top.second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}