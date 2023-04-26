//https://www.codingninjas.com/codestudio/problems/minimum-swaps-to-sort-array_1806885?leftPanelTab=1
int minSwaps(vector<int> &arr)
{
	//logic is written on new copy
	vector<pair<int, int>>SorArr(arr.size());
	for(int i = 0; i < arr.size(); i++)
	{
		SorArr[i] = {arr[i], i};
	}
	sort(SorArr.begin(), SorArr.end());
	int i = 0, swaps = 0;
	for(int i = 0; i < arr.size(); i++)
	{
		if(i != SorArr[i].second){
			int pos = SorArr[i].second;
			swap(SorArr[i], SorArr[pos]); //returning back to its original position
			swaps++;
			i--; //recheck if it is its correct position or not
		}
	}
	return swaps;
}