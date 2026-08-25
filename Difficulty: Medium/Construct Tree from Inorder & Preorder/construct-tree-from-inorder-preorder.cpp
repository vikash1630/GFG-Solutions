class Solution {
public:

    unordered_map<int, int> mp;
    int preIndex = 0;

    Node* buildTree(vector<int>& inorder, vector<int>& preorder,
                    int l, int r) {

        if (l > r)
            return NULL;

        // 1. Preorder gives root
        int rootValue = preorder[preIndex++];

        Node* root = new Node(rootValue);

        // 2. Find root in inorder
        int mid = mp[rootValue];

        // 3. Build LEFT first
        root->left = buildTree(inorder, preorder, l, mid - 1);

        // 4. Build RIGHT
        root->right = buildTree(inorder, preorder, mid + 1, r);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return buildTree(inorder, preorder, 0, inorder.size() - 1);
    }
};