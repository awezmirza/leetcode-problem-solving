class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                head = head->next;
            }
        }
        return head;
    }
};