//logic on new copy
//https://www.codingninjas.com/codestudio/problems/product-of-array-except-self_630271?leftPanelTab=0
int *getProductArrayExceptSelf(int *arr, int n)
{
    int *res = new int[n];
      int mod = 1000000007; 
    int product = 1;
    for(int i = 0; i < n; i++)
    {
        product = (product * arr[i])%mod;
        res[i] = product;   
    } 
    product = 1;
    for(int i = n-1; i > 0; i--)
    {
        res[i] = (res[i-1]*product)%mod; 
        product = (product*arr[i])%mod;
    }
    //boundary case
    res[0] = product;
    return res;
}