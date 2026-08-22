class Solution {
private:

    Node* lowestCommonAncestor(Node* root, int p, int q) {
        if (root == NULL)
            return NULL;

        if (root->data == p || root->data == q)
            return root;

        Node* left = lowestCommonAncestor(root->left, p, q);
        Node* right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;

        if (left)
            return left;

        return right;
    }

    // Store path as:
    // 0 -> left
    // 1 -> right
    bool getPath(Node* root, int target, vector<int>& path) {

        if (root == NULL)
            return false;

        if (root->data == target)
            return true;

        // Go LEFT
        path.push_back(0);

        if (getPath(root->left, target, path))
            return true;

        path.pop_back();

        // Go RIGHT
        path.push_back(1);

        if (getPath(root->right, target, path))
            return true;

        path.pop_back();

        return false;
    }

public:
    int numberOfTurns(Node* root, int p, int q) {

        Node* parent = lowestCommonAncestor(root, p, q);

        if (parent == NULL)
            return -1;

        vector<int> pathP;
        vector<int> pathQ;

        // Find path from LCA to p
        getPath(parent, p, pathP);

        // Find path from LCA to q
        getPath(parent, q, pathQ);

        // If one node is LCA
        // Example:
        // LCA -> p
        //
        // Number of turns is simply direction changes
        // in that path.
        if (pathP.empty()) {
            int turns = 0;

            for (int i = 1; i < pathQ.size(); i++) {
                if (pathQ[i] != pathQ[i - 1])
                    turns++;
            }
            if (turns == 0) return -1;
            return turns;
        }

        if (pathQ.empty()) {
            int turns = 0;

            for (int i = 1; i < pathP.size(); i++) {
                if (pathP[i] != pathP[i - 1])
                    turns++;
            }
            if (turns == 0) return -1;
            return turns;
        }

        // ------------------------------------------------
        // p and q are in different subtrees of LCA
        // So there is ALWAYS one turn at the LCA.
        //
        // Example:
        //
        //       LCA
        //       / \
        //      p   q
        //
        // Direction: LEFT -> RIGHT
        //             ^ one turn
        // ------------------------------------------------

        int turnsP = 0;
        for (int i = 1; i < pathP.size(); i++) {
            if (pathP[i] != pathP[i - 1])
                turnsP++;
        }

        int turnsQ = 0;
        for (int i = 1; i < pathQ.size(); i++) {
            if (pathQ[i] != pathQ[i - 1])
                turnsQ++;
        }

        // +1 for the turn at LCA
        return turnsP + turnsQ + 1;
    }
};