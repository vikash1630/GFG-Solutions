class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int low = *max_element(arr.begin(),arr.end());
        int high = 0;
        for (int i = 0;i<n;i++) high += arr[i];
        if (k >= n) return low;
        while (low <= high) {
            int mid = (low + high)/2;
            int res = PaintersReqToPaintAllBoards(arr,mid);
            if (res > k) {
                // It means more painters are working which is not allowed so increase maxTime which will help to decrease painters
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return low;
    }
    int PaintersReqToPaintAllBoards(vector<int>& arr,int mid) {
        int n = arr.size();
        int painters = 1;
        int TimeTook = 0;
        for (int i = 0;i<n;i++) {
            // These Loops allows us that no painter exceed the maxTime = mid so the total time required is the maxTime and if we are returning more Painters that means some Painter taking more time than this maxTime and we need this to be minimum 
            if (TimeTook + arr[i] <= mid) {
                TimeTook += arr[i];
            }
            else {
                painters++;
                TimeTook = arr[i];
            }
        }
        return painters;
    }
};