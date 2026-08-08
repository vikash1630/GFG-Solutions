class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        // return solve(s1, s2, n - 1, m - 1);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        
        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=m;j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        
        return ans;
    }
};