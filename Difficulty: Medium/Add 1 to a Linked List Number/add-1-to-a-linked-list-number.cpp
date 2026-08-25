/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  private:
    int add(Node* root, int carry) {
        if (root == NULL) return carry;
        
        int sum = root->data + add(root->next, carry);
        if (sum <= 9) {
            root->data = sum;
            carry = 0;
        }
        else {
            root->data = 0;
            carry = 1;
        }
        return carry;
    }
  public:
    Node* addOne(Node* head) {
        // code here
        Node *temp = head;
        int res = add(temp, 1);
        if (res == 1) {
            Node* val = new Node(1);
            val->next = head;
            return val;
        }
        return head;
    }
};