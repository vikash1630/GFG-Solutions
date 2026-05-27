class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n = s.size();
        string dum = s;
        int range = -1;
        // Right
        for (int i = 0;i<s.size();i++) {
            if (s[i] =='1') {
                range = i + x;
            }
            else {
                if (range >= i) {
                    dum[i] = '1';
                }
            }
        }
        // left
        range = n;
        for (int i = s.size();i>=0;i--) {
            if (s[i] == '1') {
                range = i - x;
            }
            else {
                if (range <= i) {
                    dum[i] = 1;
                }
            }
        }
        
        // Check
        for (int i = 0;i<s.size();i++) {
            if (dum[i] == '0') return false;
        }
        
        return true;
        
    }
};