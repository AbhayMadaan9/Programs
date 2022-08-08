int bs(int *arr, int left, int right, int val)
{
    int mid = (right-left)/2;
    if(arr[mid] == val) return mid;
    else if(arr[mid] > val) return bs(arr, left, mid, val);
    else if(arr[mid] < val) return bs(arr, mid, right, val);
    else return -1;
}


int binarySearch(int *input, int n, int val)
{
 int res = bs(arr, 0, n, val);
    return res;
}