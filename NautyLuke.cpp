#include <bits/stdc++.h> 
/*We will swap the first half of a row with the second half and change the colours of all the cells in the row.
We will do this for each row one by one.*/
vector<vector<int>> getFinalGrid(vector<vector<int>> &a, int n) {
    for(int i = 0; i < n; i++)
    {
            int start = 0, end = n-1; 
            while(start <= end)
            {
                swap(a[i][start], a[i][end]);
                start++;
                end--;
            }
    }
    //change every cell color
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 0) a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    return a;
}