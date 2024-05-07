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

    int dfs(ListNode* head){
        if(!head){
            return 0;
        }
        int carry = dfs(head->next);

        int num = head->val * 2 + carry;

        int toReturn = num / 10;
        head->val = num % 10;

        return toReturn;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = dfs(head);
        while(carry){
            int dig = carry % 10;
            ListNode* newNode = new ListNode(dig);
            newNode->next = head;
            head = newNode;
            carry = carry / 10;
        }
        return head;
    }
};