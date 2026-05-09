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
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans;
        stack<Node*> st;
        while (root != NULL || st.size() != NULL) {
            while (root != NULL) {
                st.push(root);
                root = root->left;
            }
            Node* ele = st.top();
            st.pop();
            root = ele->right;
            ans.push_back(ele->data);
        }
        return ans;
     }
};