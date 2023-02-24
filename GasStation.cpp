#include <bits/stdc++.h> 
//approch on new copy
//https://www.codingninjas.com/codestudio/problems/gas-tank_699834?leftPanelTab=0
int minimumStartingIndex(vector<int> &petrol, vector<int> &distance, int n) 
{
    if(accumulate(petrol.begin(), petrol.end(), 0) < accumulate(distance.begin(), distance.end(), 0)) return -1;
	 int index = 0;
	 int balance = 0;
	for(int i = 0; i < n; i++)
	{
		balance += (petrol[i] - distance[i]);
		if(balance < 0) {balance = 0; index = i+1;}
	}
	return index;
}

