#include<bits/stdc++.h>
using namespace std;

int * prefix_max(int *price, int size)
{
   int* prev_smaller = new int[size];
    stack<int>s;
    s.push(price[0]);
    for(int i = 0; i < size; i++)
    {
        while(!s.empty() and s.top() > price[i]) s.pop();
        if(!s.empty()) prev_smaller[i] = s.top();
        s.push(price[i]);
    }
    return prev_smaller;
}
int main()
{
int *arr = new int[5];
for (int i = 0; i < 5; i++)
{
    arr[i] = i;
}
arr[3] = 8;
int *ans = prefix_max(arr, 5);
for (int i = 0; i < 5; i++)
{
    cout<<ans[i] << " ";
}  
    return 0;
}