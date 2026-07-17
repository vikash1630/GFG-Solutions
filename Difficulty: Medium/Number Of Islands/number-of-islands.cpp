class DisJointset {
  public:
    vector<int> parent, size;
    
    DisJointset(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0;i<n;i++) {
            parent[i] = i;
        }
    }
    
    int findUlp(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUlp(parent[node]);
    }
    
    void UnionBySize(int u, int v) {
        int Ulp_u = findUlp(u);
        int Ulp_v = findUlp(v);
        if (Ulp_u == Ulp_v) return;
        if (size[Ulp_u] > size[Ulp_v]) {
            // Join to u
            size[Ulp_u] += size[Ulp_v];
            parent[Ulp_v] = Ulp_u;
        }
        else {
            size[Ulp_v] += size[Ulp_u];
            parent[Ulp_u] = Ulp_v;
        }
    }
 
};

class Solution {
  private:
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        // vector<vector<int>> isLand(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int tot = n * m;
        vector<int> ans;
        // Mark Islands
        int nrows[] = {0,1,0,-1};
        int ncols[] = {1,0,-1,0};
        DisJointset dis(tot);
        int comp = 0;
        for (auto &it: operators) {
            int row = it[0];
            int col = it[1];
            int curPos = row * m + col;
            if (vis[row][col] == 1) {
                ans.push_back(comp);
                continue;
            }
            vis[row][col] = 1;
            // Treating every Componenet as individual
            comp++;
            // check if besides any unconnected component
            for (int i = 0;i<4;i++) {
                int nr = row + nrows[i];
                int nc = col + ncols[i];
                
                if (isValid(nr, nc, n, m)) {
                    if (vis[nr][nc] == 1) {
                        int pos = nr * m + nc;
                        if (dis.findUlp(pos) != dis.findUlp(curPos)) {
                            comp--;
                            dis.UnionBySize(pos, curPos);
                        }
                    }
                }
            }
            
            ans.push_back(comp);
        }
        
        return ans;
    }
};
