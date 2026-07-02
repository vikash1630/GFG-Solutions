class Solution {
  public:
    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        for (int i = 0;i<n;i++) {
            int ele = arr[i];
            int ind = i;
            for (int j = i + 1;j<n;j++) {
                if (ele > arr[j]) {
                    ele = arr[j];
                    ind = j;
                }
            }
            if (ele != arr[i]) {
                arr[ind] = arr[i];
                arr[i] = ele;
            }
        }
        
        
    }
};