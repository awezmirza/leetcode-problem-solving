
//   Definition for singly-linked list.
//  struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
 
class Solution {
public:

    int getLen(ListNode* &head){
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            temp = temp->next;
            ++len;
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        int length = (getLen(head)/2);
        ListNode* temp = head;
        while(length){
            temp = temp->next;
            --length;
        }
        return temp;
    }
};