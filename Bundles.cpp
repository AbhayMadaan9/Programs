#include <bits/stdc++.h> 
//we create a hashmap of substrings of all the strings that map to its occurence then we iterate through the HashMap, let’s say the value of the current key is “count”.
//The contribution of the current key will be floor(count/K) because we need K strings with a common prefix to form one group.
//Add floor(count/k) to “finalScore”.
//https://www.codingninjas.com/codestudio/problems/bundles_985297?leftPanelTab=1
int groupsOfK(vector<string> &strList, int k)
{
   // Write your code here.
   int n=strList.size();
   unordered_map<string,int>mp;
    for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < strList[i].size(); j++)
       {
          
           string pref = strList[i].substr(0, j + 1);
           mp[pref]++;
       }
   }
   int res=0;
    for (unordered_map<string, int>::iterator i = mp.begin(); i != mp.end(); i++)
   {
       int count = i->second;
      res+=  floor(count / k);
   }

   return res;
   
}