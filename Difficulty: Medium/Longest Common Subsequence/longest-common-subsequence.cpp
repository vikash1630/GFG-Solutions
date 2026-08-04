class Solution {
  int Rec(string &s1, string &s2, int i, int j) {
      if (i == -1 || j == -1) return 0;
      
      if (s1[i] == s2[j]) return 1 + Rec(s1, s2, i - 1, j - 1);
      
      return 0 + max(Rec(s1, s2, i - 1, j), Rec(s1, s2, i , j - 1));
  }
  
  int Mem(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
      if (i <= 0 || j <= 0) return 0;
      
      if (dp[i][j] != -1) return dp[i][j];
      
      if (s1[i - 1] == s2[j - 1]) return dp[i][j] = 1 + Mem(s1, s2, i - 1, j - 1, dp);
      
      return dp[i][j] = 0 + max(Mem(s1, s2, i - 1, j, dp), Mem(s1, s2, i , j - 1, dp));
  }
  
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        
        // return Rec(s1, s2, n - 1, m - 1);
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return Mem(s1, s2, n, m, dp);
    }
};
