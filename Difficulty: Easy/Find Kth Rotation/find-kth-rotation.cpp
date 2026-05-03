class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        // If we can find the minimum element then the number of elements before it are the time its being right rotated
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int mid;
        while (low <= high) {
            if (low == high) return low;
            mid = low + (high - low)/2;
            // Check Which half to discard
            if (arr[mid] > arr[high]) {
                // Min lies in right half  
                low = mid + 1;
            }
            else {
                // Min lies in left Half including mid
                high = mid;
            }
        }
        
        // 
        return -1;
        
        
    }
};
