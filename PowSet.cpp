#include <bits/stdc++.h> 
void solve(vector<vector<int>>&ans, vector<int>v,vector<int>temp, int ind)
{
    if(ind == v.size()) 
    {
        ans.push_back(temp); return;
    }
    temp.push_back(v[ind]);
    solve(ans, v, temp, ind+1);
    temp.pop_back();
    solve(ans, v, temp, ind+1);
}
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>>ans;
    solve(ans, v, {}, 0);
    return ans;
}