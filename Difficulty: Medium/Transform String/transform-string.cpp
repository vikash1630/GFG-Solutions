class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();

        if (n != m) return -1;
        if (s1 == s2) return 0;

        int ans = 0;

        unordered_map<char, int> mpp1, mpp2;

        for (int i = 0; i < n; i++) {
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }

        // Check frequencies
        for (int i = 0; i < n; i++) {
            if (mpp1[s1[i]] != mpp2[s1[i]])
                return -1;
        }

        // Match from the end
        int i = n - 1;
        int j = n - 1;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } 
            else {
                ans++;
                i--;
            }
        }

        return ans;
    }
};