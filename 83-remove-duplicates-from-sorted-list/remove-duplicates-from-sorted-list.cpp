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
        ListNode* newHead = new ListNode();
        ListNode* temp = newHead;
        int prev = 101;
        while (head) {
            if (head->val != prev) {
                temp->next = head;
                temp = temp->next;
            }
            prev = head->val;
            head = head->next;
        }
        temp->next = NULL;
        return newHead->next;
    }
};