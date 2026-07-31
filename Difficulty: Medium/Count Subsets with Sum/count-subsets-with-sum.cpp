class Solution {
  private:
    int Rec(vector<int> &arr, int target, int n, int ind) {
        if (ind == n && target == 0) return 1;
        if (ind == n) return 0;
        
        int dontTake = Rec(arr, target, n, ind + 1);
        
        int take = 0;
        if (arr[ind] <= target) take = Rec(arr, target - arr[ind], n, ind + 1);
        
        return take + dontTake;
    }
    
    int Mem(vector<int> &arr, int target, int n, int ind, vector<vector<int>> &dp) {
        if (ind == n && target == 0) return 1;
        if (ind == n) return 0;
        
        if (dp[ind][target] != -1) return dp[ind][target];
        
        int dontTake = Mem(arr, target, n, ind + 1, dp);
        
        int take = 0;
        if (arr[ind] <= target) take = Mem(arr, target - arr[ind], n, ind + 1, dp);
    
        
        return dp[ind][target] = take + dontTake;
    }
    
    
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return Rec(arr, target, n, 0);
        return Mem(arr, target, n, 0, dp);
    }
};