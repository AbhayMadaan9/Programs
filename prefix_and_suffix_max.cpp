#include <bits/stdc++.h>
using namespace std;

long *prefix_max(long *arr, int n)
{
    long *ans = new long[n];
    int maxi = arr[0];
    // ans[0] = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
        ans[i] = maxi;
        // ans[i] = max(arr[i], arr[i-1]); //for
    }
    return ans;
}
// prefix max array
long *suffix_max(long *arr, int n)
{
    long *ans = new long[n];
    int maxi = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
        ans[i] = maxi;
    }
    return ans;
}
int main()
{
    return 0;
}