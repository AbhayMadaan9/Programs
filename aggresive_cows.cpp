#include<bits/stdc++.h>
using namespace std;
//Here we have to allocate the aggresive K cows to stalls in such a way that the distance between any two cows is as large as possible 
// In this the search space(distance between stalls) where we have to allocate the agg. cows lies between min(0) i.e not apart to max(maximum diff. between stalls)
//https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559
    
 bool isPossible(vector<int> a, int n, int cows, int minDist) {
      int cntCows = 1;
      int lastPlacedCow = a[0];
      for (int i = 1; i < n; i++) {
        if (a[i] - lastPlacedCow >= minDist) {
          cntCows++;
          lastPlacedCow = a[i];
        }
      }
      if (cntCows >= cows) return true;
      return false;
 }


int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    //.................
    //search space(distances between cows)
    int low = 0; 
    int high = *max_element(stalls.begin(), stalls.end());
    int mid;
    //considering mid as the minimum distance the agg.cows must have
    //.................

  while (low <= high) {
        mid = (low + high) >> 1;

        if (isPossible(stalls, n, k, mid)) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
  }
    return high;
    
}
int main()
{
    return 0;
}