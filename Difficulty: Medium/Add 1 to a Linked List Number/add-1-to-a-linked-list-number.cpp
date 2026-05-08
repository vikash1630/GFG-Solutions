/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* addOne(Node* head) {
        // code here
        Node* temp = ReverseLL(head);
        int carry = 1;
        Node* ans = new Node(0);
        Node* res = ans;
        int sum = 0;
        while (temp->next != NULL) {
            sum = temp->data + carry;
            if (sum > 9) {
                carry = 1;
                sum = sum%10;
            }
            else {
                carry = 0;
            }
            ans->data = sum;
            ans->next = new Node(0);
            ans = ans->next;
            temp = temp->next;
        }
        sum = temp->data + carry;
        if (sum > 9) {
            ans->data = sum%10;
            ans->next = new Node(0);
            ans = ans->next;
            ans->data = carry;
        }
        else {
            ans->data = sum;
        }
        return ReverseLL(res);
        
    }
    Node* ReverseLL(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL) {
            Node* Nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Nextnode;
        }
        return prev;
    }
};