/*
class Node {
public:
    int data;  // value stored in node
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
}
*/

class Solution {
  public:
    Node* removeDuplicates(Node* head) {

        if (head == NULL) return head;

        Node* temp = head;

        while (temp != NULL && temp->next != NULL) {

            if (temp->data == temp->next->data) {

                Node* delNode = temp->next;

                temp->next = delNode->next;

                if (delNode->next != NULL) {
                    delNode->next->prev = temp;
                }

                delNode->next = NULL;
                delNode->prev = NULL;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};