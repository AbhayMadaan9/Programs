//https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293?leftPanelTab=1
//https://www.codingninjas.com/codestudio/problems/longest-palindrome_3220?leftPanelTab=1
//app. on copy
#include <bits/stdc++.h>
using namespace std;

int solve(string &str1, string &str2, int n1, int n2, vector<vector<int>>&dp) {
  if (n1 == str1.size() || n2 == str2.size()) return 0;  // fully traversed
  if (dp[n1][n2] != -1) return dp[n1][n2];
  int ans = 0;
  if (str1[n1] == str2[n2]) ans = solve(str1, str2, n1 + 1, n2 + 1, dp) + 1;
  else 
    ans = max(solve(str1, str2, n1 + 1, n2, dp), solve(str1, str2, n1, n2 + 1, dp));
  return dp[n1][n2] = ans;
}

// LongestPallindromicSubsequence is the longest common subsequence of two strings
int LongestPallindromicSubsequence(string s) {
  string s1 = s;
  reverse(s.begin(), s.end());
  int n1 = s1.length();
  int n2 = s.length();
  vector<vector<int>> dp(n1, vector<int>(n2, -1));
  int ans = solve(s1, s, 0, 0, dp);
  return ans;
}

int minInsertion(string &str)
{
    return (str.size() - LongestPallindromicSubsequence(str));
}