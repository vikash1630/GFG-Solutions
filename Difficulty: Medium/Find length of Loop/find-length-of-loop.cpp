/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                int cnt = 1;
                slow = slow->next;
                while (slow != fast) {
                    slow = slow->next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
    }
};