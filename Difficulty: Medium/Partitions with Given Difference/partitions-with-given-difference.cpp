class Solution {
  private:
    int solve(vector<int> &arr, int ind, int k) {
        if (ind < 0 && k == 0) return 1;
        if (ind < 0 || k < 0) return 0;
        
        // dont Take
        int donttake = solve(arr, ind - 1, k);
        
        // Take 
        int take = solve(arr, ind - 1, k - arr[ind]);
        
        return take + donttake;
    }
    
    int solve(vector<int> &arr, int ind, int k, vector<vector<int>> &dp) {
        if (ind < 0 && k == 0) return 1;
        if (ind < 0 || k < 0) return 0;
        
        if (dp[ind][k] != -1) return dp[ind][k];
        
        // dont Take
        int donttake = solve(arr, ind - 1, k, dp);
        
        // Take 
        int take = solve(arr, ind - 1, k - arr[ind], dp);
        
        return dp[ind][k] = take + donttake;
    }
    
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int TS = 0;
        for (auto &it: arr) {
            TS += it;
        }
        int target = (TS + diff);
        if (target % 2 != 0) return 0;
        target = target/2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        int ans = solve(arr, n - 1, target, dp);
        return ans;
    }
};