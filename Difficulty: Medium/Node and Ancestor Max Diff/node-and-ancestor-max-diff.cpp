class Solution {
  private:
    int ans = -1e8;

    int solve(Node* root) {
        if (root == NULL)
            return 1e8;

        // Minimum value in left and right subtree
        int leftMin = solve(root->left);
        int rightMin = solve(root->right);

        // Find minimum descendant
        int minDescendant = min(leftMin, rightMin);

        // If there is a descendant, calculate difference
        if (minDescendant != 1e8) {
            ans = max(ans, root->data - minDescendant);
        }

        // Return minimum value in this subtree
        return min(root->data, minDescendant);
    }

  public:
    int maxDiff(Node* root) {
        ans = -1e8;
        solve(root);
        return ans;
    }
};