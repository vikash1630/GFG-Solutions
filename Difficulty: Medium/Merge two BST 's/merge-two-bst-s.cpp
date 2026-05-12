/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int> a;
        vector<int> b;
        getInorder(root1,a); 
        getInorder(root2,b);
        vector<int> ans;
        int i = 0,j = 0;
        int n = a.size();
        int m = b.size();
        while(i < n && j < m) {
            if (a[i] <= b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }
        while(j < m) {
            ans.push_back(b[j]);
            j++;
        }
        while(i < n) {
            ans.push_back(a[i]);
            i++;
        }
        
        return ans;
    }
    void getInorder(Node* root,vector<int>& arr) {
        if (root == NULL) return;
        getInorder(root->left,arr);
        arr.push_back(root->data);
        getInorder(root->right,arr);
    }
};