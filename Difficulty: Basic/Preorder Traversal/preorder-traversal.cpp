/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        stack<Node*> st;
        if (root != NULL) st.push(root);
        while (st.size() != 0) {
            int n = st.size();
            for (int i = 0;i<n;i++) {
                Node* ele = st.top();
                st.pop();
                if (ele->right != NULL) st.push(ele->right);
                if (ele->left != NULL) st.push(ele->left);
                ans.push_back(ele->data);
            }
        }
        return ans;
    }
};