/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        while (head != NULL) {
            if (head->data == key) return true;
            head = head->next;
        }
        return false;
    }
};
