class Solution {
public:
    bool Rec(int ind, int target, vector<int>& arr) {

        // Target achieved
        if (target == 0) return true;

        // Only one element left
        if (ind == 0) return arr[0] == target;

        // Don't take current element
        bool notTake = Rec(ind - 1, target, arr);

        // Take current element (if possible)
        bool take = false;
        if (arr[ind] <= target)
            take = Rec(ind - 1, target - arr[ind], arr);

        return take || notTake;
    }
    
    bool Mem(vector<vector<int>> &dp, int target, int n, vector<int> &arr, int ind) {
        if (target == 0) return true;
        if (ind == 0)
            return arr[0] == target;
            
        if (dp[ind][target] != -1) return dp[ind][target];
        
        // Dont take
        bool dontTake = Mem(dp, target, n, arr, ind - 1);
        
        // Take 
        bool take = false;
        if (target - arr[ind] >= 0) take = Mem(dp, target - arr[ind], n, arr, ind - 1);
        
        return dp[ind][target] = take || dontTake;
    }
    
    bool Tab(vector<int> &arr, int n, int target) {
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0;i<n;i++) dp[i][0] = 1;
        if (arr[0] <= target) dp[0][arr[0]] = 1;
        for (int i = 1;i<n;i++) {
            for (int j = 0;j<=target;j++) {
                int dontTake = dp[i - 1][j];
                int take = 0;
                if (arr[i] <= j) take = dp[i - 1][j - arr[i]];
                dp[i][j] = take || dontTake;
            }
        }
        return dp[n - 1][target];
    }

    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        // return Mem(dp, target, n, arr, n - 1);
        return Tab(arr, n, target);
        // return Rec(n - 1, target, arr);
    }
};