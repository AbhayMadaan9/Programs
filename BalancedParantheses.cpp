#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/return-parentheses_920446?leftPanelTab=1
void solve(int n, string str, vector<string>&ans, int opened, int closed)
{
    if((opened == n and closed == n )or (str.length() == 2*n)) 
    {
        ans.push_back(str);
        return;
    }
   if(closed < opened) solve(n, str+")", ans, opened, closed+1);
   if(opened < n) solve(n, str+"(", ans, opened+1, closed);

}
vector<string> balancedParantheses(int n)
{
    vector<string>ans;
    solve(n, "", ans, 0, 0);
    return ans;
}

