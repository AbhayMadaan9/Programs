#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/inverted-triangle-of-stars_1171176?leftPanelTab=1
vector<string> Triangle(int n)
{
   //Ap series of * + (2n-2)*
   vector<string>ans;
   int s = n-1; //for gaps
   for(int i = 1; i <= n; i++)
   {
      string temp = "";
      int x = s;
      while(x > 0)
      {
         temp += " ";
         x--;
      }
      s--;
      temp += "*";
     for(int j = 1; j <= 2*i-2; j++)
     {
        temp += '*';
     }

     ans.push_back(temp);
   }
   reverse(ans.begin(), ans.end());
   return ans;
}
