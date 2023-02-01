#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?leftPanelTab=1
//This method takes o(N^2) time
// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//     vector<int>res(n, -1); //initializing vector with all its value -1
//     int index = 0;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = i+1; j < n; j++)
//         {
//             if(arr[i] > arr[j]) {res[index] = arr[j];break;}   
//         }
//          index++; //we have kept it outside the 2nd loop because incase if it doesn't have smaller element but we have to increment the index
//     }
//  return res;
// }
/*-----------------------------------------------------------------------------------*/
//This method takes o(N) time because for comparison stack and we will traverse from inverse since 2nd loop is used because we traverse from starting but if we traverse from back we know its prev. value which will be stored in stack
//https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?leftPanelTab=1
vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    vector<int>res(n); 
    stack<int>stk;
    stk.push(-1);
    for(int i = n-1; i >= 0; i--)
    {
            while(arr[i] <= stk.top() and !s.empty()) 
            {
                stk.pop();
            }
            res[i] =  stk.top();
            stk.push(arr[i]);
    }
 return res;
}

int main()
{
    return 0;
}