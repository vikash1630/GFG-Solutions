/* Structure of a Binary Search Tree node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
}; */

class Solution {
	
	public:
	vector<Node*> findPreSuc(Node* root, int key) {
		// code here
		vector<Node*> res;
		int ans = key;
		Node* add = NULL;
		Node *temp = root;
		// Predecessor
		while (temp != NULL) {
			if (temp->data < key) {
			    if (ans < temp->data || ans == key) {
			        ans = temp->data;
			        add = temp;
			    }
			    temp = temp->right;
			}
			else {
			    temp = temp->left;
			}
		}
		res.push_back(add);
		temp = root;
		add = NULL;
		ans = key;
		// Successor
		while (temp != NULL) {
			if (temp->data <= key)
				temp = temp->right;
			else {
				
				if (ans == key || ans > temp->data) {
					ans = temp->data;
					add = temp;
				}
				
				temp = temp->left;
			}
		}
		res.push_back(add);
		return res;
	}
};
