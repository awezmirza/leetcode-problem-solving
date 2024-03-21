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

    ListNode* solve(ListNode* head, ListNode* nxt){
        if(!nxt) return head;

        ListNode* temp = nxt;
        ListNode* ans = solve(head->next, nxt->next);
        nxt->next = head;
        return ans;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* ans = solve(head, head->next);
        head->next = NULL;
        return ans;
    }
};