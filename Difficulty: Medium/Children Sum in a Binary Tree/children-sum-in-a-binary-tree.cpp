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
    bool isLeaf(Node* root) {
        return (root->left == NULL && root->right == NULL);
    }
    bool isSumProperty(Node *root) {
        // code here
        if (root == NULL) return true;
        queue<Node*> q;
        q.push(root);
        while (q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                Node* ele = q.front();
                q.pop();
                int a = 0,b = 0;
                if (isLeaf(ele)) continue;
                if (ele->left) {
                    a = ele->left->data;
                    q.push(ele->left);
                }
                if (ele->right) {
                    b = ele->right->data;
                    q.push(ele->right);
                }
                if (a + b != ele->data) {
                    return false;
                }
            }
        }
        return true;
    }
};