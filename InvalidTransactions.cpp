//https://www.codingninjas.com/codestudio/problems/invalid-transactions_3167809?leftPanelTab=1
vector<vector<int>> invalid_transactions(vector<vector<int>> &transactions, int n){
    vector<vector<int>> invalidTransactions;
    //check 1 (exceeds 1000)
    for(int i = 0; i < n; i++)
    {
        if(transactions[i][2] > 1000) invalidTransactions.push_back(transactions[i]);
    }
    //check 2 (transactions occurs with 60min of another transaction with same ID but diff. city)
    unordered_map<int, vector<int>> CusTrans; //ID --> its details
    for(int i = 0; i < n; i++)
    {
        auto Trans = CusTrans.find(transactions[i][0]);
        if(Trans != CusTrans.end())
        {
            int city = Trans->second[2];
            int time = Trans->second[1];
            if(city != transactions[i][3] && abs(time - transactions[i][1])<= 60) 
                {
                    invalidTransactions.push_back(transactions[i]);
                    invalidTransactions.push_back(Trans->second);
                }
        }
        else{
            CusTrans[transactions[i][0]] = {transactions[i][1], transactions[i][2], transactions[i][3]};
        }
    }
    return invalidTransactions;
}
