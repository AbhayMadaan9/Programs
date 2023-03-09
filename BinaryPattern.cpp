#include <bits/stdc++.h> 
void printPatt(int n) {
  
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j <= n-i; j++)
    {
        if(i%2==0){
                cout<<"0";
            }else{
                cout<<"1";
            }
    }
cout<<endl;
  }
}