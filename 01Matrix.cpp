#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/binary-matrix_1264291?leftPanelTab=1
//approch on copy
vector<vector<int>> findNearestZero(vector<vector<int>> &mat) 
{
	int M = mat[0].size();
	int N = mat.size();
	vector<vector<int>>NewMat = mat;
	vector<vector<bool>>visited(N, vector<bool>(M,false));
	queue<pair<pair<int, int>, int>>q; //((x, y), steps)

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(mat[i][j] == 0)
			{
				q.push({{i, j}, 0});
				visited[i][j] = true;
			}
			
		}
	}
	int rows[4] = {-1, 0, 1, 0};
	int cols[4] = {0, 1, 0, -1};

	while(!q.empty())
	{
		auto node = q.front();
		q.pop();
		int Currow = node.first.first;
		int Curcol = node.first.second;
		int steps = node.second;
		NewMat[Currow][Curcol] = steps;

		for(int i = 0; i < 4; i++)
		{
			int row = Currow+rows[i];
			int col = Curcol+cols[i];
			if(row >= 0 and row < N and col >= 0 and col < M and !visited[row][col])
			{
				visited[row][col] = true;
				q.push({{row, col}, steps+1});
			}
		}
	}
	return NewMat;
}