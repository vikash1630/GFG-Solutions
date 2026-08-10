class Solution {
  private:
    int Rec(vector<int> &arr, int ind, int prevInd, int n) {
        if (ind == n) return 0;
        if (prevInd == -1) {
            // Take 
            int take = 1 + Rec(arr, ind + 1, ind, n);
            // DontTake 
            int dontTake = Rec(arr, ind + 1, prevInd, n);
            return max(take, dontTake);
        }
        else {
            int take = 0;
            int dontTake = 0;
            if (arr[prevInd] < arr[ind]) {
                take = 1 + Rec(arr, ind + 1, ind, n);
            }
            dontTake = Rec(arr, ind + 1, prevInd, n);
            
            return max(take, dontTake);
            
        }
    }
    
    int Mem(vector<int> &arr, int ind, int prevInd, int n, vector<vector<int>> &dp) {
        if (ind == n) return 0;
        if (prevInd != -1 && dp[ind][prevInd] != -1) return dp[ind][prevInd];
        if (prevInd == -1) {
            // Take 
            int take = 1 + Mem(arr, ind + 1, ind, n, dp);
            // DontTake 
            int dontTake = Mem(arr, ind + 1, prevInd, n, dp);
            return max(take, dontTake);
        }
        else {
            int take = 0;
            int dontTake = 0;
            if (arr[prevInd] < arr[ind]) {
                take = 1 + Mem(arr, ind + 1, ind, n, dp);
            }
            dontTake = Mem(arr, ind + 1, prevInd, n, dp);
            
            return dp[ind][prevInd] = max(take, dontTake);
            
        }
    }
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        // return Rec(arr, 0, -1, n);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return Mem(arr, 0, -1, n, dp);
    }
};