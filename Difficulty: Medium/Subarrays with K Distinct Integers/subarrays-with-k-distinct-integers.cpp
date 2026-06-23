class Solution {
  private:
  int solve(vector<int> &arr, int k) {
      int n = arr.size();
      int count = 0;
      int i = 0;
      int j = 0;
      unordered_map<int,int> mpp;
      while (j < n) {
          mpp[arr[j]]++;
          while (mpp.size() > k) {
              mpp[arr[i]]--;
              if (mpp[arr[i]] == 0) mpp.erase(arr[i]);
              i++;
          }
          count += j - i + 1;
          j++;
      }
      return count;
  }
  public:
    int exactlyK(vector<int> &arr, int k) {
        // code here
        if (k == 0) return 0;
        return solve(arr,k) - solve(arr,k - 1);
    }
};