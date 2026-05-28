// User function Template for C++

class Solution {
  private:
  
    // DFS for Topological Sort
    void TopoSort(vector<int>& vis, stack<int>& st, int node,
                  vector<pair<int,int>> adj[]) {
        
        vis[node] = 1;
        
        for (auto &it : adj[node]) {
            int adjNode = it.first;
            
            if (!vis[adjNode]) {
                TopoSort(vis, st, adjNode, adj);
            }
        }
        
        st.push(node);
    }

  public:
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        // Adjacency list -> {adjNode, weight}
        vector<pair<int,int>> adj[V];
        
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }

        // Topological Sort
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                TopoSort(vis, st, i, adj);
            }
        }

        // Distance array
        vector<int> dis(V, INT_MAX);

        // Source node = 0
        dis[0] = 0;

        // Process nodes in Topological Order
        while (!st.empty()) {
            
            int node = st.top();
            st.pop();

            // If node is reachable
            if (dis[node] != INT_MAX) {
                
                for (auto &it : adj[node]) {
                    
                    int v = it.first;
                    int wt = it.second;

                    // Relaxation
                    if (dis[node] + wt < dis[v]) {
                        dis[v] = dis[node] + wt;
                    }
                }
            }
        }

        // Replace unreachable nodes with -1
        for (int i = 0; i < V; i++) {
            if (dis[i] == INT_MAX) {
                dis[i] = -1;
            }
        }

        return dis;
    }
};