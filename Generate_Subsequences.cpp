https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=1
#include<bits/stdc++.h>
void solve(string str,string output,int index, vector<string> &ans)
{
   if(index >= str.size())
    {
       return ;
    }
    else
    {
        //exclude
        solve(str, output, index+1, ans);
        //include
        int element = str[index];
        output.push_back(element);
        solve(str, output, index+1, ans);
    }
    ans.push_back(output);
   
}
vector<string> subsequences(string str)
{
    string output = "";
    vector<string> ans;
     solve(str, output, 0 , ans);
    return ans;
}

