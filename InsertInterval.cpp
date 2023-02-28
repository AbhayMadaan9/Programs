#include <bits/stdc++.h> 
//approch on new copy
//https://www.codingninjas.com/codestudio/problems/insert-interval_1102297?leftPanelTab=1
vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>>res;
    for(int i = 0; i<intervals.size(); i++)
    {
        if(intervals[i][0]>newInterval[1]) {res.push_back(newInterval);
        for(int j = i; j<intervals.size(); j++)
        {
            res.push_back(intervals[j]);
        } 
        return res;
        }
        else if(intervals[i][1] < newInterval[0]) res.push_back(intervals[i]);
        else
        {
            newInterval = {min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])};
        }
    }
    res.push_back(newInterval);
    return res;
}