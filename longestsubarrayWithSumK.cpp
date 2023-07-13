#include<bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399
//approch on new copy
//suboptimal approch
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // long long sum = 0;
    // map<int, int> prefsum; // prefix sum, index
    // int len, maxlen = INT_MIN;

    // for(int i = 0; i < a.size(); i++)
    // {
    //     sum += a[i];
    //     if(sum == k) 
    //     {
    //         len = i+1;
    //         maxlen = max(len, maxlen);
    //     }
    //     if(prefsum.find(sum-k) != prefsum.end())
    //     {
    //         int ind = prefsum[sum-k];
    //         len =  i-ind;
    //         maxlen = max(len, maxlen);
    //         prefsum.insert({sum-k, i});
    //     }
    //     else 
    //     {
    //         prefsum.insert({sum, i});
    //     }
    // } 
  //  return maxlen;
    //optimal approch
        int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}