//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    //https://practice.geeksforgeeks.org/problems/peak-element/1
    public:
    int solve(int arr[], int l, int r, int n)
{
    int mid = l + (r - l) / 2;

    if ((mid == 0 or arr[mid - 1] <= arr[mid]) and
        (arr[mid + 1] <= arr[mid] or mid == n-1))
        return mid;
 
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return solve(arr, l, mid - 1, n);
 
    else
        return solve(arr, mid + 1, r, n);
}
    int peakElement(int arr[], int n)
    {
       return solve(arr, 0, n-1, n);
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}

	return 0;
}
// } Driver Code Ends