//https://www.codingninjas.com/codestudio/problems/distinct-island_630460?leftPanelTab=1
//approch on copy
 #include <bits/stdc++.h>
 void dfs(int row, int col, vector < vector < int >> & vis,
      int** grid, vector < pair < int, int >> & vec, int row0, 
      int col0, int n, int m) {
      // mark the cell as visited
      vis[row][col] = 1;

      // coordinates - base coordinates
      vec.push_back({
        row - row0,
        col - col0
      });
      
      // delta row and delta column
      int delrow[] = {-1, 0, +1, 0}; 
      int delcol[] = {0, -1, 0, +1}; 

      // traverse all 4 neighbours
      for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        // check for valid unvisited land neighbour coordinates 
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
          dfs(nrow, ncol, vis, grid, vec, row0, col0, n, m);
        }
      }
    }

int distinctIslands(int** grid, int n, int m)
{
    vector < vector < int >> vis(n, vector < int > (m, 0));
      set < vector < pair < int, int >>> st;

      // traverse the grid
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // if not visited and is a land cell
          if (!vis[i][j] && grid[i][j] == 1) {
            vector < pair < int, int >> vec;
            dfs(i, j, vis, grid, vec, i, j, n, m);
            // store in set
            st.insert(vec);
          }
        }
      }
      return st.size();

}