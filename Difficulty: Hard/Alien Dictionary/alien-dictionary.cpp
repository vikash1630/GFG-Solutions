class Solution {
  private:
    
    vector<char> compare(string &a, string &b) {
        
        int n = min(a.size(), b.size());
        
        for (int i = 0; i < n; i++) {
            
            if (a[i] != b[i]) {
                return {a[i], b[i]};
            }
        }
        
        return {};
    }

  public:
    
    string findOrder(vector<string> &words) {

        int n = words.size();

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<int> present(26, 0);

        
        // Mark characters present
        for (auto &word : words) {
            for (auto ch : word) {
                present[ch - 'a'] = 1;
            }
        }

        
        // Build graph
        for (int i = 1; i < n; i++) {

            string a = words[i - 1];
            string b = words[i];

            
            // Invalid case
            if (a.size() > b.size() &&
                a.substr(0, b.size()) == b) {
                return "";
            }

            vector<char> ch = compare(a, b);

            if (ch.size() != 0) {

                int u = ch[0] - 'a';
                int v = ch[1] - 'a';

                adj[u].push_back(v);
                indegree[v]++;
            }
        }

        
        // Topological Sort
        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = "";

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node + 'a');

            for (auto neigh : adj[node]) {

                indegree[neigh]--;

                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        
        // Cycle exists
        int totalChars = 0;

        for (int i = 0; i < 26; i++) {
            totalChars += present[i];
        }

        if (ans.size() != totalChars) {
            return "";
        }

        return ans;
    }
};