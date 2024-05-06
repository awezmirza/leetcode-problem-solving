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

    ListNode* dfs(ListNode* head, int& greatest){
        if(head->next){
            ListNode* prevTree = dfs(head->next, greatest);
            if(head->val >= greatest){
                head->next = prevTree;
                greatest = head->val;
                return head;
            }
            return prevTree;
        }
        greatest = head->val;
        return head;
    }

    ListNode* removeNodes(ListNode* head) {
        int greatest = -1;
        return dfs(head, greatest);
    }
};