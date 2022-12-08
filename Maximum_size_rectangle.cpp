#include<bits/stdc++.h>
using namespace std;
//logic on copy  
//https://www.codingninjas.com/codestudio/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017?leftPanelTab=1
vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }


int solve_optimal(vector < int > & heights, int n)
{
    vector<int>next_smaller(n); //this vector stores the next smaller element of each element
    next_smaller = nextSmallerElement(heights,n);  //to store the values
    vector<int>prev_smaller(n); //this vector stores the prev smaller element of each element
    prev_smaller = prevSmallerElement(heights,n);  //to store the values

    int maxarea = INT_MIN;
     for(int i = 0; i < n; i++)
     {
         int length = heights[i];
         if(next_smaller[i] == -1) next_smaller[i] = n;
         int breath = next_smaller[i] - prev_smaller[i] - 1;
         int area = length*breath;
         maxarea = max(maxarea, area);
     }
    return maxarea;
}
int largestRectangleArea(vector < int > & heights) {
     int n = heights.size();
//      return solve(heights, n);
    return solve_optimal(heights, n);
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &M, int n, int m)
{
      //compute area for first row
        int area = largestRectangleArea(M[0]);
        
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                
                //row udpate: by adding previous row's value
                if(M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i-1][j];
                else
                    M[i][j] = 0;
            }
            
            //entire row is updated now
            area = max(area, largestRectangleArea(M[i]));
            
        }
        return area;
}
int main()
{
    return 0;
}