/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head, *tempSlow = NULL;
        while(fast && fast->next){
            tempSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast){
            tempSlow = slow;
            slow = slow->next;
        }
        tempSlow->next = NULL;
        stack<ListNode*> st;
        while(slow){
            st.push(slow);
            slow = slow->next;
        }

        ListNode* temp = head;

        while(!st.empty()){
            ListNode* curTemp = temp->next;
            temp->next = st.top();
            st.pop();
            temp->next->next = curTemp;
            temp = curTemp;
        }
    }
};