#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?leftPanelTab=3
/*
This is signature of helper function 'knows'.
You should not implement it, or speculate about its implementation.

bool knows(int A, int B); 
Function 'knows(A, B)' will returns "true" if the person having
id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 //step1 insert all elements to stack
   stack<int>stack;
   for(int i=0;i<n;i++){
       stack.push(i);
   }
   //step2 find potential candidate
   while(stack.size()>1){
       int a=stack.top();
       stack.pop();
       
       int b=stack.top();
       stack.pop();
       if(knows(a,b))
           stack.push(b);
       else
           stack.push(a);
   }
   int candidate=stack.top();
   
   
   //step 3 verify that the candidate is celebrity or not
    //check for the last guy in the stack left(we will check for both people and celebrity if count of people are n-1 and celebrity knows no one)
   bool celeKnows=false;
   int celecount=0;
   for(int i=0;i<n;i++){
       if(knows(candidate,i))
           celecount++;
   }
   if(celecount==0){
       celeKnows=true;
   }
   bool peopleKnows=false;
   int peoplecount=0;
   for(int i=0;i<n;i++){
       if(knows(i,candidate))
           peoplecount++;
   }
   if(peoplecount==n-1){
       peopleKnows=true;
   }
   if(peopleKnows==true && celeKnows==true){
       return candidate;
   }
   else{
       return -1;
   }
}
int main()
{
    return 0;
}