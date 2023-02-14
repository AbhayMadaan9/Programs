//https://www.codingninjas.com/codestudio/problems/sum-of-infinite-array_873335?leftPanelTab=1
#include<bits/stdc++.h>
#define mod 10000000007
long long func(vector<int> &arr, long long sum, int n, long long ind) {
    int x = (ind-1) / n + 1;
    int y = (ind-1) % n + 1;
    return (sum%mod * (x-1)%mod + accumulate(arr.begin(), arr.begin()+y, 0LL)%mod)%mod;
}

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    long long sum = accumulate(arr.begin(), arr.end(), 0LL)%mod;

    vector<int> ans;
    for (int i = 0; i < q; i++) {
        vector<long long> query = queries[i];
        long long L = query[0];
        long long R = query[1];
        int subarraySum = func(arr, sum, n, R)%mod - func(arr, sum, n, L-1)%mod;
        ans.push_back(subarraySum%mod);
    }
    return ans;
}
