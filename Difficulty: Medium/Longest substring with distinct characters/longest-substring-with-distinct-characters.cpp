class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        int i = 0;
        int j = 0;
        int count = 0;
        int ans = 0;
        unordered_map<char, int> mpp;
        while (j < n) {
            mpp[s[j]]++;
            while (i < n && mpp[s[j]] != 1) {
                mpp[s[i]]--;
                if (mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
