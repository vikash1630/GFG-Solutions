// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        
        unordered_map<int,int> mpp;
        vector<pair<int,int>> ans;

        Node* temp = head;

        while (temp != NULL) {

            if (mpp.find(target - temp->data) != mpp.end()) {

                ans.push_back({target - temp->data, temp->data});
            }

            mpp[temp->data]++;

            temp = temp->next;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};