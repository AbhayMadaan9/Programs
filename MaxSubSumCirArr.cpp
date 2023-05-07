#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/maximum-sum-circular-subarray_1264302
using namespace std;

int minimumSum(vector<int>& arr, int n) {
    int min_sum = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        min_sum = min(min_sum, sum); // update min_sum
        if(sum > 0) sum = 0; // reset sum if it becomes positive
    }
    return min_sum;
}

bool isNonPositive(vector<int> &arr, int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) return false;
    }
    return true;
}

int maxSubarraySum(vector<int> &arr, int n) {
    // if all elements are non-positive, return the maximum of them
    if(isNonPositive(arr, n)) {
        int ans = INT_MIN;
        for(auto i: arr) {
            ans = max(ans, i);
        }
        return ans;
    }
    // otherwise, apply the standard algorithm
    int tot_sum = accumulate(arr.begin(), arr.end(), 0);
    int non_contig_sum = tot_sum - minimumSum(arr, n);
    return non_contig_sum;
}
