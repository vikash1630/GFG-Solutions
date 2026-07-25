class Solution {
  private:
    // Recurrsive
    void RecSol(vector<int> height, int n,int ind,int dis,int &ans) {
        if (ind == n - 1) {
            ans = min(ans, dis);
        }
        // Go one Step
        if (ind + 1 < n) {
            dis += abs(height[ind + 1] - height[ind]);
            RecSol(height, n, ind + 1, dis, ans);
            dis -= abs(height[ind + 1] - height[ind]);
        }
        // Go two Step
        if (ind + 2 < n) {
            dis += abs(height[ind + 2] - height[ind]);
            RecSol(height, n, ind + 2, dis, ans);
            dis -= abs(height[ind + 2] - height[ind]);
        }
    }
    
    // Looks Like Memoization But its Relaxation 
    void MemSol(vector<int> height, int n, vector<int> &dp,int ind,int dis) {
        if (ind == n - 1) {
            dp[ind] = min(dp[ind], dis);
        }
        // Go One Step
        if (ind + 1 < n) {
            dis += abs(height[ind + 1] - height[ind]);
            if (dp[ind + 1] == INT_MAX || dp[ind + 1] > dis) {
                // then only compute again else no need as we already have a better option
                dp[ind + 1] = dis;
                MemSol(height, n, dp, ind + 1, dis);
            }
            dis -= abs(height[ind + 1] - height[ind]);
        }
        
        // Go Two Step
        if (ind + 2 < n) {
            dis += abs(height[ind + 2] - height[ind]);
            if (dp[ind + 2] == INT_MAX || dp[ind + 2] > dis) {
                // then only compute again else no need as we already have a better option
                dp[ind + 2] = dis;
                MemSol(height, n, dp, ind + 2, dis);
            }
            dis -= abs(height[ind + 2] - height[ind]);
        }
        
    }
  
    // True Memoization
    int TrueMem(vector<int> &height, int n, int ind, vector<int> &dp) {
        if (ind == 0) return 0;
        if (dp[ind] != -1) return dp[ind];
        // One Step
        int one = TrueMem(height, n, ind - 1, dp) + abs(height[ind] - height[ind - 1]);
        int two = INT_MAX;
        if (ind > 1) {
            two = TrueMem(height, n, ind - 2, dp) + abs(height[ind] - height[ind - 2]);
        }
        return dp[ind] = min(one, two);
        
    }
  
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        // int ans = INT_MAX;
        // RecSol(height,n,0,0,ans);
        vector<int> dp(n, -1);
        // MemSol(height, n, dp, 0, 0);
        int ans = TrueMem(height, n, n - 1, dp);
        return ans;
    }
};