#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/guided-paths/competitive-programming/content/148627/offering/1792823?leftPanelTab=1
void solve(vector<int> arr, int n, int k, int ind, vector<vector<int>> &ans,
           vector<int> SmallAns) {
//   if (k == 0) {
//     ans.push_back(SmallAns);
//     return;
//   }
  if (n == 0) {
     if (k == 0) ans.push_back(SmallAns);
    return;
  }
  // not including the current number
  solve(arr, n - 1, k, ind + 1, ans, SmallAns);
  // including the current number
  SmallAns.push_back(arr[ind]);
  solve(arr, n - 1, k - arr[ind], ind + 1, ans, SmallAns);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
  vector<vector<int>> ans;
  vector<int> SmallAns;
  solve(arr, n, k, 0, ans, SmallAns);
  return ans;
}