//GFG: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1


  void solve_rec(vector<int> adj[], vector<int>&ans, vector<bool>&visited, int cur_node)
  {
      visited[cur_node] = true;
      ans.push_back(cur_node);
        for(auto ite: adj[cur_node])
        {
              if(!visited[ite]) 
                {
                    solve_rec(adj, ans, visited, ite);
                }
        }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
      //declaration
      vector<int>ans;
      vector<bool>visited(V, false);
      
      for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      solve_rec(adj, ans, visited, 0);
    }
  }
      
      return ans;
  }
};

void dfs(int node,vector<int>& vis,vector<int>& ans,vector<int> adj[]){
    vis[node] = 1;
    ans.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,vis,ans,adj);
        }
    }
}
//https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=1
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> vis(V,0);
    vector<vector<int>> nodes;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int> ans;
            dfs(i,vis,ans,adj);
            nodes.push_back(ans);
        }
    }
    return nodes;
}

