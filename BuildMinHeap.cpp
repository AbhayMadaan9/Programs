#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0
//on old copy
void solveRec(vector<int>&arr, int Ind)
{
    int tempInd = Ind;
    int leftChild = tempInd*2+1;
    int rightChild = tempInd*2+2;

    if(arr[leftChild] < arr[tempInd] and leftChild < arr.size()) tempInd = leftChild;
    if(arr[rightChild] < arr[tempInd] and rightChild < arr.size()) tempInd = rightChild; 
    
    if(tempInd != Ind)
    {
        swap(arr[Ind], arr[tempInd]);
        solveRec(arr, tempInd);
    }
} 
vector<int> buildMinHeap(vector<int> &arr)
{
    vector<int>ans = arr;
    for(int i = ans.size()/2-1; i>=0; i--) solveRec(ans, i);
    return ans;
}
