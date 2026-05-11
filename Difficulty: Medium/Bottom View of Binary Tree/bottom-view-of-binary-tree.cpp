/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        if (root == NULL) return ans;
        map<int,int> mpp;
        queue<pair<int,Node*>> q;
        q.push({0,root});
        while (q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                auto p = q.front();
                q.pop();
                int a = p.first;
                Node* node = p.second;
                mpp[a] = node->data;
                if (node->left) q.push({a - 1,node->left});
                if (node->right) q.push({a + 1,node->right});
            }
        }
        for (auto it: mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};