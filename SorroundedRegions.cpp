//approch on copy
#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/capturing-grid_6225925?leftPanelTab=1
void dfs(vector<vector<char>> grid, int x, int y, vector<vector<bool>> &visited, int delrows[], int delcols[], int N, int M)
{
   visited[x][y] = true;
   
   for(int i = 0; i < 4; i++)
   {
      int row = delrows[i] + x;
      int col = delcols[i] + y;
      if(row >= 0 and row < N and col >= 0 and col < M and !visited[row][col] and grid[row][col] == 'O') dfs(grid, row, col, visited, delrows, delcols, N, M);
   }
}
void capture(vector<vector<char>> &grid) {
   int N = grid.size();
   int M = grid[0].size();

   vector<vector<bool>> visited(N, vector<bool>(M, false));
   int delrows[] = {-1, 0, 1, 0};
   int delcols[] = {0, 1, 0, -1};

  //boundary rows check     
   for(int i = 0; i < N; i++)
   {
      //1st row
      if(grid[0][i] ==  'O' and !visited[0][i])
      {
         dfs(grid, 0, i, visited, delrows, delcols, N, M);
      }
      //last row
      if(grid[N-1][i] ==  'O' and !visited[N-1][i])
      {
         dfs(grid, N-1, i, visited, delrows, delcols, N, M);
      }
   }
//boundary cols check
   for(int i = 0; i < N; i++)
   {
      //1st col
      if(grid[i][0] ==  'O' and !visited[i][0])
      {
         dfs(grid, i, 0, visited, delrows, delcols, N, M);
      }
      //last col
      if(grid[i][M-1] ==  'O' and !visited[i][M-1])
      {
         dfs(grid, i, M-1, visited, delrows, delcols, N, M);
      }
   }
   //convert remaining O's with X
   for(int i = 0; i < N; i++)
   {
      for(int j = 0; j < M; j++)
      {
         if(!visited[i][j] and grid[i][j] == 'O') grid[i][j] = 'X';
      }
   }
   
}
