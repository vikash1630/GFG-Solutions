/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        if (root == NULL) return {};
        vector<int> ans;
        map<int,int> mp;
        queue<pair<int,Node*>> q;
        q.push({0,root});
        int col = 0;
        while(q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                auto p = q.front();
                q.pop();
                int a = p.first;
                Node* node = p.second;
                if (!mp[a]) mp[a] = node->data;
                if (node->left) q.push({a - 1,node->left});
                if (node->right) q.push({a + 1,node->right});
            }
        }
        for (auto it: mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};