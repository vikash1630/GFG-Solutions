class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> q;
        vector<int> ans;
        q.push(0);
        vector<int> vis(adj.size(),0);
        vis[0] = 1;
        while (q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                int ele = q.front();
                q.pop();
                ans.push_back(ele);
                for (auto it: adj[ele]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};