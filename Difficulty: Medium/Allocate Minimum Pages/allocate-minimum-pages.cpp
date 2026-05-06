class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (k > n) return -1;
        int ans = 0;
        int low = *max_element(arr.begin(),arr.end());
        int high = 0;
        for (int i = 0;i<n;i++) {
            high += arr[i];
        } 
        while (low <= high) {
            int mid = low + (high - low)/2;
            int students = isPossible(arr,mid);
            if (students > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
    int isPossible(vector<int>& arr,int maxPages) {
        int i;
        int students = 1;
        int pagesPerStudent = 0;
        for (i = 0;i<arr.size();i++) {
            if (pagesPerStudent + arr[i] <= maxPages) {
                pagesPerStudent += arr[i];
            }
            else {
                students++;
                pagesPerStudent = arr[i];
            }
        }
        return students;
    }
};