#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/number-of-islands_845181?leftPanelTab=0
void dfs(vector<vector<int>> grid, int x, int y, vector<vector<bool>> &visited, int delrows[], int delcols[], int N, int M)
{
   visited[x][y] = true;
   
   for(int i = 0; i < 8; i++)
   {
      int row = delrows[i] + x;
      int col = delcols[i] + y;
      if(row >= 0 and row < N and col >= 0 and col < M and !visited[row][col] and grid[row][col] == 1) dfs(grid, row, col, visited, delrows, delcols, N, M);
   }
}
int numberOfIslands(vector<vector<int>>& grid, int n, int m)
{
     int count = 0;
     int delrows[] = {-1, -1, 0,1, 1,1, 0,-1};
   int delcols[] = {0, 1, 1, 1, 0, -1, -1,-1};

     vector<vector<bool>>visited(n, vector<bool>(m, false));
     for(int i = 0; i < n; i++)
     {
         for(int j = 0; j < m; j++)
         {
             if(grid[i][j] == 1 and !visited[i][j])
             {
                 count++;
                dfs(grid, i, j, visited, delrows, delcols, n, m);
             }
         }
     }
     return count;
}
