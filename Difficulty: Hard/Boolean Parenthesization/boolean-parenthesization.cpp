class Solution {
  int f(string &s, int i, int j, int isTrue, vector<vector<vector<int>>> &dp) {
      if (i > j) return  0;
      if (i == j) {
          if (isTrue) return s[i] == 'T';
          else return s[i] == 'F';
      }
      if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
      int ans = 0;
      for (int ind = i + 1;ind<j;ind += 2) {
          int leftTrue = f(s, i, ind - 1, 1, dp);
          int leftFalse = f(s, i, ind - 1, 0, dp);
          int rightTrue = f(s, ind + 1, j, 1, dp);
          int rightFalse = f(s, ind + 1, j, 0, dp);
          
          char op = s[ind];
          if (op == '&') {
              if (isTrue) ans += leftTrue * rightTrue;
              else ans += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
          }
          else if (op == '|') {
              if (isTrue) ans += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
              else ans += (leftFalse * rightFalse);
              
          }
          else {
              if (isTrue) ans += (rightTrue * leftFalse) + (leftTrue * rightFalse);
              else ans += (rightTrue * leftTrue) + (rightFalse * leftFalse);
          }
      }
      return dp[i][j][isTrue] = ans;
  }
  public:
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return f(s, 0, n - 1, 1, dp);
    }
};