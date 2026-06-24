class Solution {
  public:

    void solve(int ind, string &s, string str, vector<string> &ans) {
        if (ind == s.size()) {
            if (!str.empty())
                ans.push_back(str);
            return;
        }

        // Take
        solve(ind + 1, s, str + s[ind], ans);

        // Don't Take
        solve(ind + 1, s, str, ans);
    }

    vector<string> powerSet(string &s) {
        vector<string> ans;
        ans.push_back("");
        solve(0, s, "", ans);

        sort(ans.begin(), ans.end());
        return ans;
    }
};