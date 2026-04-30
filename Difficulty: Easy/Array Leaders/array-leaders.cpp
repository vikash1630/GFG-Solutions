

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans;
        ans.push_back(arr[n - 1]);
        int maxi = arr[n - 1];
        for (int i = n - 2;i>=0;i--) {
            if (arr[i] >= maxi) {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};