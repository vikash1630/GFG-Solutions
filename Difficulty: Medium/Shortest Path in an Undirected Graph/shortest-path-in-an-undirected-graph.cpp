class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n + 1];
        for (int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int> parent(n + 1);
        // for(int i=1;i<=n;i++)parent[i] = i;
        vector<int> dis(n + 1,INT_MAX);
        dis[1] = 0;
        parent[1] = 1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // {dis,node}
        pq.push({0,1});
        while (pq.size() != 0) {
            int node = pq.top().second;
            int disFromSrc = pq.top().first;
            pq.pop();
            if (disFromSrc > dis[node]) continue;
            for (auto &it: adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dis[node] + wt < dis[v]) {
                    parent[v] = node;
                    dis[v] = dis[node] + wt;
                    pq.push({dis[v], v});
                }
            }
        }
        if (dis[n] == INT_MAX) return {-1};
        vector<int> ans;
        int i = n;
        while (i != 1) {
            ans.push_back(i);
            i = parent[i];
        }
        ans.push_back(1);
        ans.push_back(dis[n]);
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};