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

    int gcd(int num1, int num2) {
        if (num1 < num2) {
            return gcd(num2, num1);
        }

        int r1 = num1;
        int r2 = num2;

        while (r2 != 0) {
            int rem = r1 % r2;
            r1 = r2;
            r2 = rem;
        }
        return r1;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* num1 = head;
        ListNode* num2 = head->next;

        while (num2) {
            int gcdInt = gcd(num1->val, num2->val);
            ListNode* gcdNode = new ListNode(gcdInt, num2);
            num1->next = gcdNode;
            num1 = num2;
            num2 = num2->next;
        }
        return head;
    }
};