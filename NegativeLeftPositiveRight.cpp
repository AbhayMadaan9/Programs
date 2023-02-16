#include <bits/stdc++.h> 
//also on new copy
vector<int> separateNegativeAndPositive(vector<int> &nums){

    // vector<int>ans;
    // for(int i = 0; i < nums.size(); i++)
    // {
    //     if(nums[i] < 0) ans.push_back(nums[i]);
    // }
    // for(int i = 0; i < nums.size(); i++)
    // {
    //     if(nums[i] >= 0) ans.push_back(nums[i]);
    // }
    // return ans;


    // sort(nums.begin(), nums.end());
    // return nums;

    //use idea of quick sort of taking pivot and making its left less than pivot and right greater than pivot
    int pivot = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] < 0) swap(nums[i], nums[pivot++]);
    }
    return nums;
}