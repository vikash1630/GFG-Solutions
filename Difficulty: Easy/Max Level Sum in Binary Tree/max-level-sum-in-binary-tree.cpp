/* Structure of tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    int maxLevelSum(Node* root) {
        // code here
        queue<Node*> q;
        q.push(root);
        int ans = INT_MIN;
        while (q.size() != 0) {
            int sum = 0;
            int n = q.size();
            for (int i = 0;i<n;i++) {
                auto node = q.front();
                sum += node->data;
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans = max(sum,ans);
        }
        return ans;
    }
};