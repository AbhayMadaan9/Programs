//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
//https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1
    int inSequence(int A, int B, int C){
        if(C==0) return (A==B);
        int x = (B-A);        //series a+(n-1)d form according acc. to it +1 extra is removed which is of no use here
        if(x%C == 0 and x/C>=0) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends