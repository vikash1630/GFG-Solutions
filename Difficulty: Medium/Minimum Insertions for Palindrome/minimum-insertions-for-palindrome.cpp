class Solution {
  private:
    int Mem(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) return 0;
            
        if (dp[i][j] != -1) return dp[i][j];
        
        // dontTake
        int dontTake1 = Mem(s1, s2, i - 1, j, dp);
        int dontTake2 = Mem(s1, s2, i, j - 1, dp);
        
        // Take 
        int take = 0;
        if (s1[i] == s2[j]) {
            take = 1 + Mem(s1, s2, i - 1, j - 1, dp);
        }
        return dp[i][j] = max(take, max(dontTake1, dontTake2));
    }
  public:
    int findMinInsertions(string &s) {
        // code here
        int n = s.size();
        string p = s;
        reverse(p.begin(), p.end());
        // int lcs = Rec(s, p, n - 1, n - 1);
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int lcs = Mem(s, p, n - 1, n - 1, dp);
        
        return n - lcs;
    }
};