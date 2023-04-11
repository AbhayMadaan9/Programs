#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/guided-paths/competitive-programming/content/148627/offering/1792819?leftPanelTab=1
void solve(vector<vector<int>>&ans, int n, int a, int b, int c)
{
    if(n > 0)
    {
        solve(ans, n-1, a, c, b);
        ans.push_back({a, c});
        solve(ans, n-1, b, a, c);
    }
}
vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>>ans;
    solve(ans, n, 1, 2, 3);
    return ans;
}
int main()
{
    vector<vector<int>>ans = towerOfHanoi(5);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i][0]<<"->"<<ans[i][1]<<endl;
    }
    
    return 0;
}
//coding ninjas
