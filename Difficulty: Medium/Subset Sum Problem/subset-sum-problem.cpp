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

    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return Mem(dp, target, n, arr, n - 1);
        // return Rec(n - 1, target, arr);
    }
};