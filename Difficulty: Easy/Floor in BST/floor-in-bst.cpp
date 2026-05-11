/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
        int val = k;
        while (root != NULL) {
            if (root->data == val) {
                return val;
            }
            else if (root->data > val) {
                root = root->left;
            }
            else {
                ans = root->data;
                root = root->right;
            }
        }
        return ans;
    }
};