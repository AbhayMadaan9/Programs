#include<bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/codestudio/problems/largest-rectangle-in-a-histogram_1058184?leftPanelTab=1
//Brute force approch
int left_most_index(vector < int > & arr, int n, int current)
{
        if(current == 0) return -1; //for the current to be at start there is nothing on it's left
       int i = current-1;
 
    while(arr[current] >= arr[i] and i > 0)
    {
        i--;
    }
    return i;
}
int right_most_index(vector < int > & arr, int n, int current)
{
    int i = current+1;
    if(current == n-1) return current+1; //for the current to be at end there is nothing on it's right
    while(arr[current] >= arr[i] and i < n)
    {
        i++;
    }
    return i;
}
int solve_fessible(vector < int > & heights, int n)
{
    int maxarea = INT_MIN;
     for(int i = 0; i < n; i++)
     {
         int left = left_most_index(heights, n, i);  
         int right = right_most_index(heights, n, i);
         int area = heights[i]*(right - left-1);
         maxarea = max(maxarea, area);
     }
    return maxarea;
}

//optimal solution(using next smaller elment function solved,Pre requiste: https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?leftPanelTab=1)
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
int largestRectangle(vector < int > & heights) {
     int n = heights.size();
//      return solve(heights, n);
    return solve_optimal(heights, n);
 }
int main()
{
    return 0;
}