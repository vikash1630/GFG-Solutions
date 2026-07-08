class Solution {
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    void bfs(queue<pair<int,int>> &q, vector<vector<int>> &vis,
             vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m &&
                   !vis[nr][nc] &&
                   mat[nr][nc] >= mat[r][c]) {

                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }

public:
    int countCoordinates(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pac(n, vector<int>(m,0));
        vector<vector<int>> atl(n, vector<int>(m,0));

        queue<pair<int,int>> qp, qa;

        // Station P (top row + left column)
        for(int i=0;i<n;i++) {
            if(!pac[i][0]) {
                pac[i][0]=1;
                qp.push({i,0});
            }
        }

        for(int j=0;j<m;j++) {
            if(!pac[0][j]) {
                pac[0][j]=1;
                qp.push({0,j});
            }
        }

        // Station Q (bottom row + right column)
        for(int i=0;i<n;i++) {
            if(!atl[i][m-1]) {
                atl[i][m-1]=1;
                qa.push({i,m-1});
            }
        }

        for(int j=0;j<m;j++) {
            if(!atl[n-1][j]) {
                atl[n-1][j]=1;
                qa.push({n-1,j});
            }
        }

        bfs(qp, pac, mat);
        bfs(qa, atl, mat);

        int ans = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pac[i][j] && atl[i][j])
                    ans++;
            }
        }

        return ans;
    }
};