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
    vector<int> ans;
    
    bool isLeaf(Node* root) {
        return (root->left == NULL && root->right == NULL);
    }
  
    void dfsLeft(Node* root) {
        if (root == NULL || isLeaf(root)) return;
        ans.push_back(root->data);
        if (root->left != NULL) {
            dfsLeft(root->left);
        }
        else dfsLeft(root->right);
    }
  
    void dfsLeaf(Node* root) {
        if (root == NULL) return;
        if (isLeaf(root)) ans.push_back(root->data);
        dfsLeaf(root->left);
        dfsLeaf(root->right);
    }
    
    void dfsRight(Node* root) {
        if (root == NULL || isLeaf(root)) return;
        if (root->right == NULL) {
            dfsRight(root->left);
        }
        else {
            dfsRight(root->right);
        }
        ans.push_back(root->data); // Add While Returning
    }
  
  
  
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if (root == NULL) return ans;
        if (isLeaf(root)) {
            return {root->data};
        }
        ans.push_back(root->data);
        dfsLeft(root->left);
        dfsLeaf(root);
        dfsRight(root->right);
        return ans;
    }
};