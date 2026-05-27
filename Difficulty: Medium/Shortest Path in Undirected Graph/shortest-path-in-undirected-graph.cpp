class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int> adj[V];
        for (int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        // BFS
        int dis = 0;
        vector<int> ans(V,-1);
        queue<int> q;
        vector<int> vis(V,0);
        q.push(src);
        vis[src] = 1;
        ans[src] = 0;
        while (q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                int node = q.front();
                q.pop();
                for (auto &it: adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        ans[it] = ans[node] + 1;
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};
