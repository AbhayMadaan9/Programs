//https://www.codingninjas.com/codestudio/problems/jump-game_893178?leftPanelTab=1
//approch on copy
int minJumps(vector<int> &arr) 
{
    int jump = 0;
    int steps = arr[0] - 1;  //considering that we have already taken first step 
    int max_reach = arr[0];
    int n = arr.size();
    
    //Base conditions
    if(n == 1) return 0; 
    if(arr[0] == 0) return -1;
    
    
    for(int i = 1; i < n; i++)  
    {
        if(max_reach >= n) return jump+1;
        if(i > max_reach) return -1;
        max_reach = max(max_reach, i + arr[i]);
        steps--;
        if(steps == 0) 
        {
            steps = max_reach - i;
            jump++;
        }
            
    }
    return -1;
}