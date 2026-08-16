class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        if (arr[0] >= 0) return arr[0];
        int i = 0;
        int ans = 1;
        while (i < n && arr[i] < 0) {
            ans *= arr[i];
            i++;
        }
        if (ans > 0) ans /= arr[i - 1];
        while (i < n && arr[i] == 0) i++;
        while (i<n) {
            ans *= arr[i];
            i++;
        }
        return ans;
    }
};