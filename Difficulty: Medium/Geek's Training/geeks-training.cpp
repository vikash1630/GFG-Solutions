class Solution {
  private:
    // Recursively
    int rec(vector<vector<int>> &mat, int last, int ind) {
        if (ind == 0) {
            int maxi = 0;
            for (int i = 0;i<3;i++) {
                if (i != last) {
                    maxi = max(maxi, mat[0][i]);
                }
            }
            return maxi;
        }
        
        // If not base case try all
        int maxi = 0;
        for (int i = 0;i<3;i++) {
            if (i != last) {
                int points = mat[ind][i] + rec(mat, i, ind - 1);
                maxi = max(maxi, points);
            }
        }
        
        return maxi;
    }
    
    // Memomization
    int mem(vector<vector<int>> &mat, int last, int ind, vector<vector<int>> &dp) {
        if (ind == 0) {
            int maxi = 0;
            for (int i = 0;i<3;i++) {
                if (i != last) {
                    maxi = max(maxi,mat[0][i]);
                }
            }
            return dp[ind][last] = maxi;
        }
        
        if (dp[ind][last] != 0) return dp[ind][last];
        
        int maxi = 0;
        for (int i = 0;i<3;i++) {
            if (i != last) {
                int points = mat[ind][i] + mem(mat, i, ind - 1, dp);
                maxi = max(maxi, points);
            }
        }
        
        return dp[ind][last] = maxi;
        
    }
    
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        // return rec(mat, 3, n - 1);
        return mem(mat, 3, n - 1, dp);
    }
};