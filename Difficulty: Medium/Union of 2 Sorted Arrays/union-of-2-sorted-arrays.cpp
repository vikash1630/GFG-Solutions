class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        vector<int> ans;
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        while (i<n && j<m) {
            if (a[i] >= b[j]) {
                if (ans.size() > 0 && ans[ans.size() - 1] == b[j]) {
                    j++;
                    continue;
                }
                ans.push_back(b[j]);
                j++;
            }
            else {
                if (ans.size() > 0 && ans[ans.size() - 1] == a[i]) {
                    i++;
                    continue;
                }
                ans.push_back(a[i]);
                i++;
            }
        }
        while (i<n) {
            if (ans.size() > 0 && ans[ans.size() - 1] == a[i]) {
                i++;
                continue;
            }
            ans.push_back(a[i]);
            i++;
        }
        while (j<m) {
            if (ans.size() > 0 && ans[ans.size() - 1] == b[j]) {
                j++;
                continue;
            }
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};