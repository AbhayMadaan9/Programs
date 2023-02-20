#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/one-segment_1459115?leftPanelTab=1
bool oneSegment(string str) {

	//linear traversal and do while loop for 0's and 1's and count for 1's
	//use map to find frequency of 1's this
	int count = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '0')
		{
			while(str[i] == str[i+1]) i++;
		}
		if(str[i] == '1')
		{
			count++;
			while(str[i] == str[i+1]) i++;
		}
	}
	return (count <= 1);
}