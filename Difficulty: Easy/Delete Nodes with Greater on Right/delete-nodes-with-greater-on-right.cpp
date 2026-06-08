/* Structure of a Linked List node
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
  public:
    Node *compute(Node *head) {
        // code here
        if (head == NULL || head->next == NULL) return head;
        vector<int> dum;
        Node* temp = head;
        while (temp != NULL) {
            dum.push_back(temp->data);
            temp = temp->next;
        }
        vector<int> ans;
        ans.push_back(dum[dum.size() - 1]);
        int ch = dum[dum.size() - 1];
        for (int j = dum.size() - 2;j>=0;j--) {
            if (dum[j] >= ch) ans.push_back(dum[j]);
            ch = max(dum[j],ch);
        }
        reverse(ans.begin(),ans.end());
        Node* res = new Node(ans[0]);
        Node* curr = res;

        for (int i = 1; i < ans.size(); i++) {
            curr->next = new Node(ans[i]);
            curr = curr->next;
        }
        
        return res;
    }
};