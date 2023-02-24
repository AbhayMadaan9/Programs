#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/hard_6581571?leftPanelTab=0 
//logic is we don't need to perform the operations we just compare and check how much nmbers are incremented
int getMinOperations(vector<int> &final)
{
	int operations = final[0];
	for(int i = 1; i < final.size(); i++)
	{
		if(final[i] > final[i-1]) operations += (final[i]-final[i-1]);
	}
	return operations;
}

