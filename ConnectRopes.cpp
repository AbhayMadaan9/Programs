long long connectRopes(int* arr, int n)
{
    //https://www.codingninjas.com/codestudio/problems/connect-n-ropes-with-minimum-cost_630476?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1
    //logic is we take two min length rope and add till all are connected.
    priority_queue<long long, vector<long long>, greater<long long>>pq;
    for(int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }   
    long long cost = 0;

    while(pq.size() > 1)
    {
        if(pq.size() >= 2){
        int rope1 = pq.top();
        pq.pop();
         int rope2 = pq.top();
        pq.pop();
        long long JoinCost = rope1+rope2;
        cost += JoinCost;
        pq.push(JoinCost);
        }
        else break;
    }
    return cost;
}
