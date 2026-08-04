class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_map<int, int> mpp;
        for (int i = 0;i<arr.size();i++) {
            if (mpp.find(target - arr[i]) != mpp.end()) return true;
            mpp[arr[i]]++;
        }
        return false;
    }
};