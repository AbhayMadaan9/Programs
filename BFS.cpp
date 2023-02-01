// GFG-https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // initiations
        vector<int> ans;
        queue<int> q;
        vector<bool> visited(V, false);

        // pushing 0th vertex to queue
        q.push(0);
        visited[0] = true;

        // traversing
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            // first sort then pickup from them
            set<int> temp;
            for (auto ite : adj[node])
            {
                if (!visited[ite])
                {
                    temp.insert(ite);
                    visited[ite] = true;
                }
            }
            // Now traverse the temp array and push to the queue
            for (auto it : temp)
            {
                q.push(it);
            }
        }

        return ans;
    }
};

// codingninjas- https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?leftPanelTab=0

// some of the test cases are incorrect my code is correct
#include <bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // change representation to adjaceny list
    vector<int> adj_list[vertex]; // special data structure array of vector<int> type
    for (int i = 0; i < edges.size(); i++)
    {
        adj_list[edges[i].first].push_back(edges[i].second);
        adj_list[edges[i].second].push_back(edges[i].first);
    }

    // initiations
    vector<int> ans;
    queue<int> q;
    vector<bool> visited(vertex, false);

    // pushing 0th vertex to queue
    q.push(0);
    visited[0] = true;

    // traversing
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        // first sort then pickup from them
        set<int> temp;
        for (auto ite : adj_list[node])
        {
            if (!visited[ite])
            {
                temp.insert(ite);
                visited[ite] = true;
            }
        }
        // Now traverse the temp array and push to the queue
        for (auto it : temp)
        {
            q.push(it);
        }
    }

    return ans;
}


 vector<int> BFS(int vertex, vector<pair<int, int>> edges) {   
     unordered_map<int,set<int>> adjlist;

for (int i = 0; i < edges.size(); i++)
{
    int u = edges[i].first;
    int v = edges[i].second;
    adjlist[u].insert(v);
    adjlist[v].insert(u);
}
unordered_map<int, bool> check;
vector<int> ans;
for (int i = 0; i < vertex; i++)
{
    if (!check[i])
    {
        queue<int> q;
        q.push(i);
        check[i] = 1;
        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();
            ans.push_back(frontnode);
            for (auto k : adjlist[frontnode])
            {
                if (!check[k])
                {
                    q.push(k);
                    check[k] = 1;
                }
            }
        }
    }
}
return ans;
}