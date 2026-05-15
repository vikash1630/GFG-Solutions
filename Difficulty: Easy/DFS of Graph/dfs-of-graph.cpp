class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> vis(adj.size(),0);
        vector<int> ans;
        int start = 0;
        solveDFS(start,vis,ans,adj);
        return ans;
        
    }
    
    void solveDFS(int node,vector<int>& vis,vector<int>& ans,vector<vector<int>>& adj) {
        vis[node] = 1;
        ans.push_back(node);
        for (auto it: adj[node]) {
            if (!vis[it]) {
                solveDFS(it,vis,ans,adj);
            }
        }
    }
};



