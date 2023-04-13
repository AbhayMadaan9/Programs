#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/reversing-a-queue_982934?leftPanelTab=1
queue<int> reverseQueue(queue<int> q) {
  stack<int> st;

  while (!q.empty()) {
    st.push(q.front());
    q.pop();
  }
  while (!st.empty()) {
    q.push(st.top());
    st.pop();
  }

  return q;
}
