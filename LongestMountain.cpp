int longestMountain(int *arr, int n) {
    //https://www.codingninjas.com/codestudio/problems/longest-mountain-subarray_893069?leftPanelTab=1
// approch 1: for each subarray check if it is mountain array and get max among
// all of them it requires n*3 time approch 2: make one traversal check for each
// element if it is peak point or not if yes then traverse to its left and right
// till it is valid then get max among all of them
  int longest = 0;
  if (n < 3)
    return 0;
  for (int i = 1; i < n - 1; i++) {
    int len = 0;
    if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) // peak point
    {
      len = 1;
      int left = i;
      int right = i;
      while (left > 0 && arr[left] > arr[left - 1])
        len++, left--;
      while (right < n - 1 && arr[right] > arr[right + 1])
        len++, right++;
      longest = max(longest, len);
    }
  }
  return longest;
}
