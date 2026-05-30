// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dis(V,1e8);
        dis[src] = 0;
        for (int i = 0;i< V - 1;i++) {
            for (auto &it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                // Relaxation
                if (dis[u] != 1e8 && dis[u] + wt < dis[v]) {
                    dis[v] = dis[u] + wt;
                }
            }
        }
        
        // Nth Relaxation to check if a negative cycle is there
        for (auto &it : edges) {
            if (dis[it[0]] != 1e8 && dis[it[0]] + it[2] < dis[it[1]]) {
                return {-1};
            }
        }
        
        return dis;    
    }
};
