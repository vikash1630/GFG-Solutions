class Solution {
  private:
    int solve(vector<vector<int>> grid, int n, int m, int i, int j) {
        if (i == n - 1 && j == m - 1) return 1;
        if (i == n || j == m) return 0;
        
        // Go down
        int down = 0;
        if (grid[i][j] == 0) down = solve(grid, n, m, i + 1, j);
        
        // Go right
        int right = 0;
        if (grid[i][j] == 0) right = solve(grid, n, m, i, j + 1);
        
        return down + right;
    }
    
    int solve(vector<vector<int>> grid, int n, int m, int i, int j, vector<vector<int>> &dp) {
        if (i == n - 1 && j == m - 1) return 1;
        if (i == n || j == m) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        // Go down
        int down = 0;
        if (grid[i][j] == 0) down = solve(grid, n, m, i + 1, j, dp);
        
        // Go right
        int right = 0;
        if (grid[i][j] == 0) right = solve(grid, n, m, i, j + 1, dp);
        
        return dp[i][j] = down + right;
    }
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        if (grid[n - 1][m - 1] == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, n, m, 0, 0, dp);
        
    }
};

