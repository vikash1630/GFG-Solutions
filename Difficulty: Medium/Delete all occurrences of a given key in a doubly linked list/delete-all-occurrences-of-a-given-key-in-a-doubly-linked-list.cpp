/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        
        Node* temp = *head_ref;

        while (temp->next != NULL) {

            Node* nextNode = temp->next;

            if (temp->data == x) {
                

                if (temp->prev != NULL) {
                    temp->prev->next = nextNode;
                }
                else {
                    *head_ref = nextNode;
                }

                nextNode->prev = temp->prev;

                temp->next = NULL;
                temp->prev = NULL;
            }

            temp = nextNode;
        }

        if (temp->data == x) {

            temp->prev->next = NULL;

            temp->next = NULL;
            temp->prev = NULL;
        }
        
    }
};