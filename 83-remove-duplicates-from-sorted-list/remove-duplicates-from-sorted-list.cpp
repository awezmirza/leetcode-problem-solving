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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> st;
        ListNode* newHead = new ListNode();
        ListNode* temp = newHead;
        while (head) {
            if (!st.count(head->val)) {
                temp->next = head;
                temp = temp->next;
                st.insert(head->val);
            }
            head = head->next;
        }
        temp->next = NULL;
        return newHead->next;
    }
};