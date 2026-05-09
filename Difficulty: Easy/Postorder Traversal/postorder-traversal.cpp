/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> ans;
        stack<Node*> st1;
        stack<Node*> st2;
        if (root == NULL) return {};
        if (root != NULL) st1.push(root);
        while (st1.size() != 0) {
            int n = st1.size();
            for (int i = 0;i<n;i++) {
                Node* ele = st1.top();
                st1.pop();
                st2.push(ele);
                if (ele->left != NULL) st1.push(ele->left); 
                if (ele->right != NULL) st1.push(ele->right); 
            }
        }
        while (st2.size() != 0) {
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        return ans;
    }
};