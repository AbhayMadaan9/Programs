#include <bits/stdc++.h> 
//approches on new copy
//https://www.codingninjas.com/codestudio/problems/longest-substring-without-repeating-characters_758894?leftPanelTab=1
int lengthOfLongestSubstring(string &input) {
    //bruteForce approch
    //  unordered_set<char>ust;
    // int ans = 1;
    // for(int i = 0; i < input.length(); i++)
    // {
    //     for(int j = i; j < input.length(); j++)
    //     {
    //         if(ust.size() > 1) {
    //             if(ans < ust.size()) ans = ust.size();
    //         }
    //         if(ust.find(input[j]) == ust.end()) ust.insert(input[j]);
    //         else break;
    //     }
    //     ust.clear();
    // }
    // return ans;
  unordered_map<char, int> ump;
    int n = input.length();
    int len = 0, left = 0, right = 0;
    while (right < n) {
        if (ump.find(input[right]) != ump.end() && ump[input[right]] >= left) {
            left = ump[input[right]] + 1;
        }
        ump[input[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

