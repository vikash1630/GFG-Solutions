class Solution {
  private:
    int solve(vector<vector<int>>& mat, int cr, int cc, int xd, int yd, int n, int m, vector<vector<int>> &vis, int &ans, int &dis) {
        vis[cr][cc] = 1;
        dis++;
        if (cr == xd && cc == yd) {
            int a = dis;
            dis--;
            vis[cr][cc] = 0;
            return a;
        }
        int rows[] = {0,1,0,-1};
        int cols[] = {1,0,-1,0};
        for (int i = 0;i<4;i++) {
            int nr = cr + rows[i];
            int nc = cc + cols[i];
            if (nr >= 0 && nc >= 0 && nc < m && nr < n && vis[nr][nc] == 0 && mat[nr][nc] == 1) {
                int disReq = solve(mat, nr, nc, xd, yd, n, m, vis, ans, dis);
                ans = max(ans, disReq);
            }
        }
        dis--;
        vis[cr][cc] = 0;
        return 0;
    }
  public:
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        int ans = 0;
        if (xs == xd && ys == yd) return 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dis = -1;
        int a = solve(mat, xs, ys, xd, yd, n, m, vis, ans, dis);
        if (ans == 0) return -1;
        return ans;
    }
};



