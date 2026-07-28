class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<int> dist(V, INT_MAX);
        vector<vector<pair<int, int>>> adjL(V);
        for (int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adjL[u].push_back({v, wt});
            adjL[v].push_back({u, wt});
        }
        dist[src] = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(src);
        while (pq.size() != 0) {
            int n = pq.size();
            for (int i = 0;i<n;i++) {
                int node = pq.top();
                pq.pop();
                if (dist[node] == INT_MAX) continue;
                for (auto &it: adjL[node]) {
                    int nextNode = it.first;
                    int wt = it.second;
                    if (wt + dist[node] < dist[nextNode]) {
                        dist[nextNode] = wt + dist[node];
                        pq.push(nextNode);
                    }
                }
            }
        }
        if (dist[dest] != INT_MAX) return dist[dest];
        return -1;
    }
};