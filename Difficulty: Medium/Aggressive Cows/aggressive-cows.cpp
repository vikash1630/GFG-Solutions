class Solution {
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int low = arr[1] - arr[1];
        int high = arr[n - 1] - arr[0];
        int ans = -1;
        while (low <= high) {
            int mid = (low + high)/2;
            int cows = 1;
            int prevCowInd = 0;
            for (int i = 1;i<n;i++) {
                if (arr[i] - arr[prevCowInd] >= mid) {
                    prevCowInd = i;
                    cows++;
                }
            }
            if (cows >= k) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};