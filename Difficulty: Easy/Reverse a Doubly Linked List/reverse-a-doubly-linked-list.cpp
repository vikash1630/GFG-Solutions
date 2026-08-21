/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if (head == NULL) return NULL;
        Node* temp = head;
        Node* temp2 = NULL;
        while (temp != NULL) {
            temp2 = temp->next;
            temp->next = temp->prev;
            temp->prev = temp2;
            if (temp2 == NULL) return temp;
            temp = temp2;
        }
        return NULL;
    }
};