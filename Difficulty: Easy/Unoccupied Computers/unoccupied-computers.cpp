class Solution {
  public:
    int solve(int n, string s) {
        // code here
        int avail = n;
        int freq[26];
        int assign[26];
        int ans = 0;
        for (int i = 0;i<26;i++) {
            freq[i] = 0;
            assign[i] = 0;
        }
        for (auto &ch: s) {
            freq[ch - 'A']++;
            if (freq[ch - 'A'] == 1) {
                if (avail) {
                    assign[ch - 'A'] = 1;
                    avail--;
                }
                else ans++;
            }
            else {
                if (assign[ch - 'A']) avail++;
            }
        }
        return ans;
    }
};
