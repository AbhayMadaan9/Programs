//https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149?leftPanelTab=1
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
  vector<int> ans;
  int i = 0, j = 0;
  while (i < n and j < m) {
    if (arr1[i] == arr2[j]) {
      ans.push_back(arr1[i]);
      i++;
      j++;
    }
    else if (arr1[i] > arr2[j]) {
      j++;
    }
    else {
      i++;
    }
  }
  if (ans.empty()) return {-1};
  else return ans;
}
