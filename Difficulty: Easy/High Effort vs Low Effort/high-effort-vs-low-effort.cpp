class Solution {
  private:
    int Rec(vector<int>& h, vector<int>& l, int ind) {
        if (ind < 0) return 0;
        
        // perform low task
        int lt = l[ind] + Rec(h, l, ind - 1);
        
        // Perform high task
        int ht = h[ind] + Rec(h, l, ind - 2);
        
        // Perform no task
        int nt = Rec(h, l, ind - 1);
        
        return max(ht, max(lt, nt));
    }
    
    int Mem(vector<int>& h, vector<int>& l, int ind, vector<int>& dp) {
        if (ind < 0) return 0;
        
        if (dp[ind] != -1) return dp[ind];
        
        // perform low task
        int lt = l[ind] + Mem(h, l, ind - 1, dp);
        
        // Perform high task
        int ht = h[ind] + Mem(h, l, ind - 2, dp);
        
        // Perform no task
        int nt = Mem(h, l, ind - 1, dp);
        
        return dp[ind] = max(ht, max(lt, nt));
    }
    
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n = h.size();
        vector<int> dp(n, -1);
        return Mem(h, l, n - 1, dp);
    }
};