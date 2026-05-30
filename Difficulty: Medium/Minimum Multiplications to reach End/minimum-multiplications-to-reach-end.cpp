class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        int mod = 1000;
        start = start%mod;
        if (start == end) return 0;
        vector<int> vis(mod,-1);
        queue<pair<int,int>> q;
        q.push({0,start});
        vis[start] = 1;
        while (!q.empty()) {
            int dis = q.front().first;
            int ele = q.front().second;
            q.pop();
            for (auto &it: arr) {
                int mult = (1LL * ele * it)%mod;
                if (mult == end) return dis + 1;
                if (vis[mult] == -1) {
                    vis[mult] = 1;
                    q.push({dis + 1,mult});
                }
            }
        }
        return -1;
    }
};