class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        int left = 0;
        int right = 0;
        int ans = 1;
        unordered_map<char, int> mpp;
        while (right < n) {
            mpp[s[right]]++;
            while (left < right && mpp[s[right]] > 1) {
                mpp[s[left]]--;
                if (mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
