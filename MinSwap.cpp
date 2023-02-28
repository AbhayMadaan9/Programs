#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/maximum-swap_1262144?leftPanelTab=0
int maximumSwap(int n) {
  string temp = to_string(n);
  int ans = n;
  for (int i = 0; i <= temp.length() - 1; i++) {
    for (int j = temp.length() - 1; j >= i; j--) {
      if (temp[i] < temp[j]) {
        swap(temp[i], temp[j]); 
		ans = max(ans, stoi(temp)); 
		swap(temp[i], temp[j]);
      }
    }
  }

  return ans;
}