class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = high + (low - high)/2;
            if (arr[mid] > target) {
                ans = min(ans,mid);
                high--;
            }
            else low++;
        }
        return ans;
    }
};
