class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> adj[V];
        for (int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        // DFS
        vector<int> vis(V,-1);
        for (int i = 0;i<V;i++) {
            if (vis[i] == -1) {
                bool flag = dfs(adj,vis,i,0);
                if (!flag) return false;
            }
        }
        return true;
    }
    
    bool dfs(vector<int> adj[],vector<int> &vis,int z,int col) {
        vis[z] = col;
        int setCol;
        if (col == 1) setCol = 0;
        else setCol = 1;
        for (int i = 0;i<adj[z].size();i++) {
            if (vis[adj[z][i]] != -1) {
                if (vis[adj[z][i]] != setCol) return false;
            }
            else {
                bool flag = dfs(adj,vis,adj[z][i],setCol);
                if (!flag) return false;
            }
        }
        return true;
    }
};