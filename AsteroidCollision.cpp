#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/asteroid-collision_977232?leftPanelTab=1
vector<int> collidingAsteroids(vector<int> &arr) {
  stack<int> stones;
  for (int curr : arr) {
    if (stones.empty() || curr > 0) {
      stones.push(curr);
    } else {
      while (!stones.empty() && stones.top() > 0 && stones.top() < abs(curr)) {
        stones.pop();
      }
      if (stones.empty() || stones.top() < 0) {
        stones.push(curr);
      } else if (stones.top() == abs(curr)) {
        stones.pop();
      }
    }
  }
  vector<int> ans(stones.size());
  int i = stones.size() - 1;
  while (!stones.empty()) {
    ans[i--] = stones.top();
    stones.pop();
  }

  return ans;
}