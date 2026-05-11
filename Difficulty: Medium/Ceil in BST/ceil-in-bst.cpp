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
    int findCeil(Node* root, int x) {
        // code here
        int ans = -1;
        while (root != NULL) {
            if (root->data == x) return x;
            else if (root->data > x) {
                if (ans == -1) ans = root->data;
                else ans = min(ans,root->data);
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return ans;
    }
};
