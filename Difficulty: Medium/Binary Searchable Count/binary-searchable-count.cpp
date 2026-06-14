class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        // code here
        int ans = 0;
        int n = arr.size();
        for (int i = 0;i<n;i++) {
            if (binarySearch(arr[i],arr) == true) ans++;
        }
        return ans;
    }
    bool binarySearch(int k,vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high)/2;
            if (arr[mid] == k) return true;
            else if (arr[mid] > k) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};