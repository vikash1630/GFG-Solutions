class Solution {
  private:
    int solve(int row, int ind, int n,vector<vector<int>> &mat, vector<vector<int>> &dp) {
        if (row == n) return 0;
        if (dp[row][ind] != -1) return dp[row][ind];
        int next = solve(row + 1, (ind + 1)%3, n, mat, dp);
        int nextNext = solve(row + 1, (ind + 2)%3, n, mat, dp);
        return dp[row][ind] = mat[row][ind] + min(next, nextNext);
    }
    
    
  public:
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0;i<3;i++) {
            int sum = solve(0, i, n, mat, dp);
            ans = min(ans, sum);
        }
        return ans;
    }
};