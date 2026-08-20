/* Structure of Binary Tree Node
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
  private:
    void InOrderTraversal(Node* root, vector<int> &ans) {
        if (root == NULL) return;
        
        InOrderTraversal(root->left, ans);
        ans.push_back(root->data);
        InOrderTraversal(root->right, ans);
        return;
    } 
  public:
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans;
        InOrderTraversal(root, ans);
        return ans;
    }
};