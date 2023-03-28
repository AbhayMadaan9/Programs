#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/minimum-numbers-required_1459113?leftPanelTab=1
int findMinNumbers(vector<int> &arr, int sum, int maxVal) {
	int CurSum = accumulate(arr.begin(), arr.end(), 0);
	int reqsum = abs(CurSum-sum);
	int numsReq = reqsum/maxVal;
	if(reqsum%maxVal > 0) numsReq +=1;
	return numsReq;
}