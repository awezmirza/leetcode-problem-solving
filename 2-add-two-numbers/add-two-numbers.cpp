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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        ListNode* ansHead = new ListNode();
        ListNode* ansPtr = ansHead;
        int carry = 0;
        while (p1 && p2) {
            ansPtr->next = new ListNode();
            ansPtr = ansPtr->next;
            int sum = p1->val + p2->val + carry;
            ansPtr->val = sum % 10;
            carry = sum / 10;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1) {
            ansPtr->next = new ListNode();
            ansPtr = ansPtr->next;
            int sum = p1->val + carry;
            ansPtr->val = sum % 10;
            carry = sum / 10;
            p1 = p1->next;
        }
        while (p2) {
            ansPtr->next = new ListNode();
            ansPtr = ansPtr->next;
            int sum = p2->val + carry;
            ansPtr->val = sum % 10;
            carry = sum / 10;
            p2 = p2->next;
        }

        if (carry) {
            ansPtr->next = new ListNode();
            ansPtr = ansPtr->next;
            ansPtr->val = carry;
        }

        return ansHead = ansHead->next;
    }
};