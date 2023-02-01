#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/stock-span_99652?leftPanelTab=1
//also in copy

//we have to find the index of last concecutive smaller for the current element and subtract it with current element index which will give span 
int* stockSpan(int *price, int size)  {
    //last concecutive smaller using stack (similiar to NGE) and calculating span using that
	int* spans = new int[size];
    stack<int>s; //index of the current element
    spans[0] = 1;
   s.push(0);
    for(int i = 1; i < size; i++)
    {
        //do dry run for better understanding
        while(!s.empty() and price[s.top()] < price[i]) s.pop();
       //two cases- 1.if just prev is greater then no span 2.else means smaller is present
        if(s.empty()) spans[i] = i+1;
        else spans[i] = i - s.top();
        
        s.push(i);
    }
    //we can seperately do the part of calculating last concecutive smaller elements for each price array elements and find the spans by substracting last concecutive smaller index of current element and index of the current element 
    return spans;
    
}
int main()
{
    return 0;
}