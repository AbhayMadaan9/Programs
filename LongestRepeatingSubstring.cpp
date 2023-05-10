#include <bits/stdc++.h>
//approch on yellow copy
//https://www.codingninjas.com/codestudio/problems/longest-repeating-substring_980523?leftPanelTab=1
int longestRepeatingSubstring(string str, int k) {
    int n = str.length();
    if(n < k) return -1;
    
    int maxLen = 1, left = 0, right = 0, cnt = 0;
    unordered_map<char, int> freq;
    while(right < n) {
        freq[str[right]]++;
        cnt = max(cnt, freq[str[right]]);
        right++;
        
        if(right - left > cnt + k) {
            freq[str[left]]--;
            left++;
        }
        
        maxLen = max(maxLen, right - left);
    }
    return maxLen;
}

