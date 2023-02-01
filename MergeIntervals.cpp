#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/merge-intervals_699917?leftPanelTab=0
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
//on copy too
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);
    int i = 0; //pointer at mergedIntervals
    for (int j = 1; j < intervals.size(); j++) {
      //condition of overlapping
        if (intervals[j][0] <= mergedIntervals[i][1]) {
            mergedIntervals[i][1] = max(mergedIntervals[i][1], intervals[j][1]);
        } else {
            mergedIntervals.push_back(intervals[j]);
            i++;
        }
    }
    return mergedIntervals;
}