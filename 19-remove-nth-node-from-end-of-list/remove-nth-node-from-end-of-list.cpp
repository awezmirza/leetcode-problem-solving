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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fNode = head;
        while(fNode){
            if(n>0) n--;
            else{
                prev = curr;
                curr = curr->next;
            }
            fNode = fNode->next;
        }
        if(prev) prev->next = curr->next;
        else return head->next;
        return head;
    }
};