/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        ListNode* nextKaNext = node->next->next;
        node->val = next->val;
        node->next = nextKaNext;
    }
};