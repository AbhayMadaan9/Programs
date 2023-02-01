#include<bits/stdc++.h>
using namespace std;


bool solve(vector<int>arr, int n)
{
    int lst = n-1;
    for (int i = n-2; i >= 0; i--)
    {
        if(lst+arr[i] >= lst) lst = i;
    }
    if(lst == 0) return true;
    else return false;
}
int main()
{
    int n; 
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout << solve(arr, n)<<endl;
    
    
    return 0;
}