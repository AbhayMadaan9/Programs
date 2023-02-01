#include<bits/stdc++.h>
using namespace std;
//approch on copy
//https://www.codingninjas.com/codestudio/problems/sort-an-array-of-0s-1s-and-2s_892977?leftPanelTab=1

void sortArray(vector<int>& nums, int n)
{
    int lo = 0, mid = 0, hi = n-1;
    
  while (mid <= hi) { 
            switch (nums[mid]) { 

            // If the element is 0 
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
  }
}

int main()
{
    return 0;
}