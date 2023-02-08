//https://www.codingninjas.com/codestudio/problems/longest-common-substring_1214702?leftPanelTab=0
//approch on copy similiar to longest common subsequence slight modification.
int solveTab(string & str1, string & str2, int n1, int n2)
{
    
   vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
   //base cases
    for(int i = 0; i <= n1; i++) dp[i][0] = 0;
     for(int i = 0; i <= n2; i++) dp[0][i] = 0;
     int ans = 0;
   for(int i = 1; i <= n1; i++)
   {
       for(int j = 1; j <= n2; j++)
       {
         if (str1[i-1] == str2[j-1]) {
           dp[i][j] = 1 + dp[i - 1][j - 1];
           ans = max(ans, dp[i][j]);
         }
         else dp[i][j] = 0;
       }
   }
    return ans;
}

int LCSubStr(string &str1, string &str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
   // return solveMem(str1, str2, 0, 0, dp);
    return solveTab(str1, str2, n1, n2);
}

