class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        vector<int> dis(V, INT_MIN);
        vector<vector<pair<int, int>>> adjL(V);
        for (int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adjL[u].push_back({v, wt});
        }
        queue<int> q;
        q.push(src);
        dis[src] = 0;
        while (q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                int node = q.front();
                q.pop();
                for (auto &it: adjL[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dis[v] < dis[node] + wt) {
                        q.push(v);
                        dis[v] = dis[node] + wt;
                    }
                }
            }
        }
        return dis;
    }
};