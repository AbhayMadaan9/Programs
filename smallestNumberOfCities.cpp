#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance_1264289?leftPanelTab=1
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) 
{
vector<vector<int>> ans(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			ans[it[0]][it[1]] = it[2];
			ans[it[1]][it[0]] = it[2];
		}
		for (int i = 0; i < n; i++) ans[i][i] = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (ans[i][k] == INT_MAX || ans[k][j] == INT_MAX)
						continue;
					ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
				}
			}
		}

   int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (ans[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;
}