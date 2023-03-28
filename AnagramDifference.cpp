#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/anagram-difference_799485
int getMinimumAnagramDifference(string &str1, string &str2) {
    unordered_map<char, int>ump;
    for(auto &i: str1) ump[i]++;
    for(auto &j: str2) ump[j]--;
    int ans = 0;
    for(auto &k: ump) ans += abs(k.second);
    return ans/2;
}