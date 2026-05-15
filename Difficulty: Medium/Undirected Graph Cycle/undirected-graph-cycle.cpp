class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for (int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int vis[V] = {0};
        // {element,parent}
        for (int i = 0;i<V;i++) {
            if (vis[i] == 0) {
                if (bfs(i,adj,vis)) return true;
            }
        }
        return false;
    }
    bool bfs(int node,vector<int> adj[],int vis[]) {
        vis[node] = 1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        while(q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                int ele = q.front().first;
                int par = q.front().second;
                q.pop();
                for (auto it: adj[ele]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push({it,ele});
                    }
                    else {
                        if (it != par) return true;
                    }
                }
            }
        }
        return false;
    }
};