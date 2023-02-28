//xor of doing the same value results to 0 else 1 
//dry run on new copy
//https://www.codingninjas.com/codestudio/problems/find-unique_625159?leftPanelTab=1
int findUnique(int *arr, int size)
{
    //Write your code here
        int ans =0;

    for(int i =0 ;i<size;i++) {
        ans ^=arr[i];

    }

    return ans;
}