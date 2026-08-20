/* Binary Tree Node Structure
class Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void dfs(Node *root, unordered_map<int, int> &mpp) {
        if (root == NULL) return;
        mpp[root->data]++;
        dfs(root->left, mpp);
        dfs(root->right, mpp);
        return;
    }
    bool findTarget(Node *root, int target) {
        // code here.
        unordered_map<int, int> mpp;
        dfs(root, mpp);
        for (auto &it: mpp) {
            int key = it.first;
            if (target - key == key) {
                if (mpp[key] == 2) return true;
                continue;
            }
            if (mpp.find(target - key) != mpp.end()) return true;
        }
        return false;
    }
};