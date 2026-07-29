class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int cnt = 1;
        int ele = arr[0];
        for (int i = 1;i<arr.size();i++) {
            if (ele + 1 == arr[i]) {
                ele = arr[i];
            }
            else {
                cnt++;
                ele = arr[i];
            }
        }
        return cnt;
    }
};
