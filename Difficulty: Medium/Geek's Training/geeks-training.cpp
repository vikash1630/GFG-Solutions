class Solution {
  private:
    int solve(vector<vector<int>>& mat, int row, int col, int n) {
        if (row == n) return 0;
        
        int ans1 = mat[row][col] + solve(mat, row + 1, ((col + 1)%3), n);
        int ans2 = mat[row][col] + solve(mat, row + 1, ((col + 2)%3), n);
        
        return max(ans1, ans2);
    }
    
    int solve(vector<vector<int>>& mat, int row, int col, int n, vector<vector<int>> &dp) {
        if (row == n) return 0;
        if (dp[row][col] != -1) return dp[row][col];
        int ans1 = mat[row][col] + solve(mat, row + 1, ((col + 1)%3), n, dp);
        int ans2 = mat[row][col] + solve(mat, row + 1, ((col + 2)%3), n, dp);
        
        return dp[row][col] = max(ans1, ans2);
    }
    
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int ans = -1e8;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0;i<3;i++) {
            int sum = solve(mat, 0, i, n, dp);
            ans = max(sum, ans);
        }
        return ans;
    }
};