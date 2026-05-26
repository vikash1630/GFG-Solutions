class Solution {
  private:
  void dfs(vector<int> adj[],vector<int>& vis,int z,stack<int>& st) {
      vis[z] = 1;
      for (auto it : adj[z]) {
          if (!vis[it]) dfs(adj,vis,it,st);
      }
      st.push(z);
  }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        for (int i = 0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> vis(V,0);
        stack<int> st;
        for (int i = 0;i<V;i++) {
            if (!vis[i]) dfs(adj,vis,i,st);
        }
        
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};