#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/find-minimum-sum-subarray-of-given-size_873368?leftPanelTab=1
int minSubarraySum(int arr[], int n, int k) {
  // brute force
  //   int ans = INT_MAX;
  //   for (int i = 0; i < n; i++) {
  //     int sum = 0;
  //     if (i + k-1  < n) {
  //       for (int j = i; j < i + k; j++) {
  //         sum += arr[j];
  //       }
  //       ans = min(ans, sum);
  //     }
  //   }
  //   return ans;

  // sliding window approch
    int i = 0, j = k-1, sum = 0, minSum = 0;
    for(int x = i; x <= j; x++) {
        sum += arr[x];
    }
    minSum = sum;
    while(j+1 < n) {
        sum = sum - arr[i] + arr[j+1];
        minSum = min(minSum, sum);
        i++;
        j++;
    }
    return minSum;

}
