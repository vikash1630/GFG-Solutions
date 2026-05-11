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
    void getParent(Node* root,unordered_map<Node*,Node*>& mp) {
        queue<Node*> q;
        q.push(root);
        while (q.size() != NULL) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                Node* ele = q.front();
                q.pop();
                if (ele->left) {
                    q.push(ele->left);
                    mp[ele->left] = ele;
                }
                if (ele->right) {
                    q.push(ele->right);
                    mp[ele->right] = ele;
                }
            }
        }
    }
    int minTime(Node* root, int target) {
        // code here
        if (root == NULL) return 0;
        unordered_map<Node*,Node*> mp;
        getParent(root,mp);
        Node* tg = findTarget(root,target);
        unordered_map<Node*,bool> vis;
        queue<Node*> q;
        q.push(tg);
        vis[tg] = true;
        int t = -1;
        while (q.size() != 0) {
            t++;
            int n = q.size();
            for (int i = 0;i<n;i++) {
                Node* ele = q.front();
                q.pop();
                if (ele->left && !vis[ele->left]) {
                    q.push(ele->left);
                    vis[ele->left] = true;
                }
                if (ele->right && !vis[ele->right]) {
                    q.push(ele->right);
                    vis[ele->right] = true;
                }
                if (mp.find(ele) != mp.end() && !vis[mp[ele]]) {
                    q.push(mp[ele]);
                    vis[mp[ele]] = true;
                }
            }
        }
        return t;
    }
    Node* findTarget(Node* root,int target) {
        if (root == NULL) return NULL;
        if (root->data == target) return root;
        Node* left = findTarget(root->left,target);
        if (left) return left;
        Node* right = findTarget(root->right,target);
        if (right) return right;
        return NULL;
        
    }
};