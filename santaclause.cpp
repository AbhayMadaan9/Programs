#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/santa-claus-and-his-magic-bag_985284?leftPanelTab=0
vector<int> giftsLeft(int n, int k, int q, vector<int> demands) 
{
  vector<int> res;
  int count = n;
  for (int i = 0; i < demands.size(); i++) {
    if (demands[i] > count)
      res.push_back(-1);
    else {
      if (count <= k)
        count = n;
      else if (count - demands[i] < k)
        count = n;
      else
        count -= demands[i];
      res.push_back(count);
    }
  }
  return res;
}