class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {

        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans;

        // 8 directions
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] != word[0])
                    continue;

                bool found = false;

                for (int dir = 0; dir < 8; dir++) {

                    int x = i;
                    int y = j;
                    int p = 1;

                    for (; p < word.size(); p++) {

                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            break;

                        if (mat[nx][ny] != word[p])
                            break;

                        x = nx;
                        y = ny;
                    }

                    if (p == word.size()) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};