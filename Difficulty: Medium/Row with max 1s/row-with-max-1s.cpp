// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ind = -1;
        int maxi = -1;
        int m = arr[0].size();
        for (int i = 0;i<arr.size();i++) {
            int cnt = lowerBound(arr[i], m);
            if (cnt > maxi) {
                ind = i;
                maxi = cnt;
            }
        }
        return ind;
    }
    int lowerBound(vector<int>& arr,int n) {
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high)/2;
            if (arr[mid] == 1) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if (high == n - 1 && low == n) return -1;
        return (n - high); // Number of ones in the row
    }
};