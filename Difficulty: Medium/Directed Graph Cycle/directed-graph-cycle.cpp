class Solution {
  private:
    bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &pathVis,int z) {
        vis[z] = 1;
        pathVis[z] = 1;
        for (auto it : adj[z]) {
            if (vis[it] == 0) {
                if (dfs(adj,vis,pathVis,it) == true) return true;
            }
            else if (pathVis[it] == 1) return true;
        }
        pathVis[z] = 0;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        for (int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for (int i = 0;i<V;i++) {
            if (vis[i] == 0) {
                if (dfs(adj,vis,pathVis,i) == true) return true;
            }
        }
        return false;
    }
};