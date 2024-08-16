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

    ListNode* reverseList(ListNode* head, ListNode* prev) {
        if (!head) {
            return prev;
        }

        ListNode* temp = head->next;
        head->next = prev;
        return reverseList(temp, head);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        while (l1 || l2) {
            if (l1) {
                st1.push(l1->val);
                l1 = l1->next;
            } 
            if (l2) {
                st2.push(l2->val);
                l2 = l2->next;
            }
        }

        ListNode* ansHead = new ListNode();
        ListNode* temp = ansHead;

        int carry = 0;
        while (!st1.empty() || !st2.empty() || carry) {
            int st1top = st1.empty() ? 0 : st1.top();
            int st2top = st2.empty() ? 0 : st2.top();
            int sum = st1top + st2top + carry;
            if (!st1.empty()) {
                st1.pop();
            }
            if (!st2.empty()) {
                st2.pop();
            }
            carry = sum / 10;
            int dig = sum % 10;
            temp->next = new ListNode(dig);
            temp = temp->next;
        }
        
        return reverseList(ansHead->next, NULL);
    }
};