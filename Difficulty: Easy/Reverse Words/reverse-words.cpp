class Solution {
	public:
	string reverseWords(string &s) {
		// code here
		int n = s.size();
		string ans = "";
		string str = "";
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '.') {
				if (str != "") {
					reverse(str.begin(), str.end());
					ans += str;
					ans += '.';
				}
				str = "";
			}
			else {
				str += s[i];
			}
		}
		if (str != "") {
			reverse(str.begin(), str.end());
			ans += str;
		}
		if (ans[ans.size() - 1] == '.') ans.pop_back();
		return ans;
	}
};
