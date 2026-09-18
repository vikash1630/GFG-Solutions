/* Binary Tree Node Structure
class Node {
public:
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
    void dfs(Node *root, set<int> &st) {
        if (root == NULL) return;
        st.insert(root->data);
        dfs(root->left, st);
        dfs(root->right, st);
        return;
    }
  public:
    int absDiff(Node *root) {
        // code here
        set<int> st;
        dfs(root, st);

        int curr = *st.rbegin();
        st.erase(prev(st.end()));

        int ans = INT_MAX;

        while (!st.empty()) 
        {
            ans = min(ans, abs(curr - *st.rbegin()));
            curr = *st.rbegin();
            st.erase(prev(st.end()));
        }
        return ans;
    }
};