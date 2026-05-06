class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        if (k > stalls.size()) return 0;
        sort(stalls.begin(),stalls.end());
        int left = 0;
        int n = stalls.size();
        int right = stalls[n - 1];
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (isPossible(stalls,k,mid)) {
                // Min distance with mid is possible so to make it maximize try something larger than this mid
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
    
    bool isPossible(vector<int>& stalls,int k,int dis) {
        int n = stalls.size();
        int cnt = 1; // Cow at 0th index
        int nextPossiblePos = stalls[0] + dis;
        for (int i = 1;i<n;i++) {
            if (stalls[i] >= nextPossiblePos) {
                // Placed Second Cow
                cnt++;
                nextPossiblePos = stalls[i] + dis;
            }
            if (cnt == k) return true;
        }
        return false;
    }
};