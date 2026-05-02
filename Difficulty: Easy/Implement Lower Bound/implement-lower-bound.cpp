class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0;
        int ans = n;
        int high = n - 1;
        while (low <= high) {
            int mid = high + (low - high)/2;
            if (arr[mid] >= target) {
                ans = min(ans,mid);
                high--;
            }
            else low++;
        }
        return ans;
    }
};
