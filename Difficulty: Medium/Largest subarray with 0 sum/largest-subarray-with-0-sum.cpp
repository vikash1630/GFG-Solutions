class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        int prefixSum = 0;
        int left = 0;
        int right = 0;
        int start = 0;
        int ans = 0;
        
        unordered_map<int,int> mpp;
        for (int i = 0;i<n;i++) {
            prefixSum += arr[i];
            if (prefixSum == 0) {
                ans = i + 1;
            }
            int check = prefixSum;
            if (mpp.find(check) != mpp.end()) {
                ans = max(ans, i - mpp[check]);
            }
            if (mpp.find(prefixSum) == mpp.end()) {
                mpp[prefixSum] = i;
            }
            
        }
        return ans;
    }
};