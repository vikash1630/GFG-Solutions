class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<pair<int,int>> adj[V];
        for (auto &it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> dis(V,INT_MAX);
        dis[src] = 0;
        pq.push({dis[src], src});
        while (!pq.empty()) {
            int node = pq.top().second;
            int disOfNodeFromSrc = pq.top().first;
            pq.pop();
            if (disOfNodeFromSrc > dis[node]) continue;
            for (auto &it: adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (disOfNodeFromSrc + wt < dis[v]) {
                    dis[v] = disOfNodeFromSrc + wt;
                    // update pq so some other may get the better ones
                    pq.push({dis[v],v});
                }
            }
        }
        return dis;
    }
};



