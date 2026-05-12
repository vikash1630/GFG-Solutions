/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* ans1 = NULL;
    Node* ans2 = NULL;
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        pre(root,key);
        suc(root,key);
        return {ans1,ans2};
    }
    void pre(Node* root,int key) {
        if (root == NULL) return;
        if (root->data < key) {
            ans1 = root;
            pre(root->right,key);
        } 
        else pre(root->left,key);
    }
    void suc(Node* root,int key) {
        if (root == NULL) return;
        if (root->data > key) {
            ans2 = root;
            suc(root->left,key);
        } 
        else suc(root->right,key);
    }
};