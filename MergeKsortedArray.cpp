#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=1
// logic1: merge all and sort them
// logic2: for each array use priority queue to find max/min element and then
// push them into ans.
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k) {
  vector<int> ans;
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 0; i < k; i++) {
    vector<int> temp = kArrays[i];
    for (auto j : temp) {
      q.push(j);
    }
  }
  while(!q.empty())
  {
      ans.push_back(q.top());
      q.pop();
  }

  return ans;
}
