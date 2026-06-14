class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        bool left = false;
        bool right = true; // Current Direction
        bool up = false;
        bool down = false;
        int n = mat.size();
        int m = mat[0].size();
        int i = 0;
        int j = 0;
        int row = 0;
        int col = 0;
        while (i >= 0 && j >= 0 && i < n && j < m) {
            if (mat[i][j] == 0) {
                // Move in Same Direction
                if (right) {
                    j++;
                }
                else if (down) {
                    i++;
                }
                else if (left) {
                    j--;
                }
                else {
                    i--;
                }
            }
            else {
                mat[i][j] = 0;
                if (right) {
                    right = false;
                    down = true;
                    i++;
                }
                else if (down) {
                    down = false;
                    left = true;
                    j--;
                }
                else if (left) {
                    left = false;
                    up = true;
                    i--;
                }
                else {
                    up = false;
                    right = true;
                    j++;
                }
            }
        }
        if (right) {
            row = i;
            col = m - 1;
        }
        else if (down) {
            row = n - 1;
            col = j;
        }
        else if (left) {
            row = i;
            col = 0;
        }
        else {
            row = 0;
            col = j;
        }
        return {row, col};
    }
};