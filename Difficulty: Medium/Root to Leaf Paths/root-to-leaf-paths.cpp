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
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> dum;
        dfs(root, ans, dum);
        return ans;
    }
    
    void dfs(Node* root, vector<vector<int>>& ans, vector<int>& dum) {
        
        if (root == NULL) return;
        
        dum.push_back(root->data);
        
        if (isLeaf(root)) {
            ans.push_back(dum);
            dum.pop_back();
            return;
        }
        
        dfs(root->left, ans, dum);
        dfs(root->right, ans, dum);
        
        dum.pop_back();
    }
    
    bool isLeaf(Node* root) {
        return (root->left == NULL && root->right == NULL);
    }
    
};