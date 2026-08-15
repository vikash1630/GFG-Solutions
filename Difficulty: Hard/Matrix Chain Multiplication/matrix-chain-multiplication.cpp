class Solution {
  private:
    int f(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for (int k = i;k<j;k++) {
            int sum = arr[i - 1] * arr[k] * arr[j] + f(arr, i, k, dp) + f(arr, k + 1, j, dp);
            mini = min(sum, mini);
        }
        return dp[i][j] = mini;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(arr, 1, n - 1, dp);
    }
};