#include<bits/stdc++.h>
using namespace std;

//on copy
//https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_980531?leftPanelTab=1
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {

  int l = 0, h = m * n - 1;
 
  while (l <= h) {
    int mid = l + (h - l) / 2;

    int val = mat[mid / n][mid % n];
    if (val == target)
      return true;
 
    if (val < target)
      l = mid + 1;
    else
      h = mid - 1;
  }
 
  return false;

//     for(int i = 0; i < m; i++)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             if(mat[i][j] == target) return true;
//         }
//     }
//     return false;
}
int main()
{
    return 0;
}