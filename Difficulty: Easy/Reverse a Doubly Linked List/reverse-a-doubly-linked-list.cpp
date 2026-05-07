/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
public:
    Node *reverse(Node *head) {

        Node* curr = head;
        Node* temp = NULL;

        while (curr != NULL) {

            // Swap prev and next
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // Move to next node
            curr = curr->prev;
        }

        // New head
        if (temp != NULL) {
            head = temp->prev;
        }

        return head;
    }
};