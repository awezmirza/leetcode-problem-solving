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

    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        stack<ListNode*> st;
        while(head){
            st.push(head);
            head = head->next;
        }
        ListNode* ans = st.top();
        ListNode* it = ans;
        st.pop();
        while(!st.empty()){
            it->next = st.top();
            it = it->next;
            st.pop();
        }
        it->next = NULL;
        return ans;
    }
};