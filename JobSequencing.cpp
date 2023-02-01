//https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460
#include<bits/stdc++.h>
bool cmp( vector<int> &a, const vector<int> &b)
{
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int size = jobs.size();
    //sorting the jobs vector wrt max deadline
   sort(jobs.begin(), jobs.end(), cmp);
    int maxdeadline = jobs[0][0];
    
        for (int j = 0; j < size; j++)
        {
            maxdeadline = max(maxdeadline, jobs[j][0]);
        }
      vector<bool> timeslot(maxdeadline+1, 0);
    
    int totalprofit = 0;
    for (int i = 0; i < jobs.size(); i++)
        {
        int currdeadline = jobs[i][0];
        int currprofit = jobs[i][1];
        for(int k = currdeadline; k > 0; k--)
        {
            if(timeslot[k] == 0)
            {
                timeslot[k] = 1;
                totalprofit += currprofit;
                break;
            }
        }
    }
    return totalprofit;
}
