class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        for (int i = 0;i<n;i++) {
            arr.push_back(arr[i]);
        }
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = INT_MIN;
        while (right < n + m) {
            sum += arr[right];
            if (right - left + 1 > m) {
                sum -= arr[left];
                left++;
            }
            ans = max(ans, sum);
            right++;
        }
        return ans;
        
    }
};