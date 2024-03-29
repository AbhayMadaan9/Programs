#include<bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/maximum-meetings_1062658?leftPanelTab=1
//approch on copy
struct meeting {
   int start;
   int end;
   int pos;
};
 bool static comparator(struct meeting m1, meeting m2) {
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.pos < m2.pos) return true;
         return false;
 }
vector<int> maximumMeetings(vector<int> &s, vector<int> &e) {
    int n = s.size();
    struct meeting meet[n];
      for (int i = 0; i < n; i++) {
         meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
      }

      sort(meet, meet + n, comparator);

      vector < int > answer;

      int limit = meet[0].end;
      answer.push_back(meet[0].pos);

      for (int i = 1; i < n; i++) {
         if (meet[i].start > limit) {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
         }
      }
    return answer;
}
