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

    int solve(ListNode* head, int& ans) {
        if (!head) {
            return 0;
        }
        int val = solve(head->next, ans);
        if (head->val == 1) {
            ans += (1 << val);
        }
        return val + 1;
    }

    int getDecimalValue(ListNode* head) {
        int ans = 0;
        solve(head, ans);
        return ans;
    }
};