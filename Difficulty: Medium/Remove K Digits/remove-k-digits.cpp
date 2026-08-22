class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        int n = s.size();
        stack<char> st;
        st.push(s[0]);
        int i = 0;
        for (i = 1;i<n;i++) {
            while (k > 0 && !st.empty() && st.top() > s[i]) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        string ans = "";
        while (k>0 && !st.empty()) {
            st.pop();
            k--;
        }
        if (st.empty()) return "0";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        i = 0;
        
        while (i < ans.size() && ans[i] == '0')
            i++;
        
        ans = ans.substr(i);
        while (k > 0) {
            ans.pop_back();
            k--;
        }
        if (ans == "") return "0";
        return ans;
    }
};