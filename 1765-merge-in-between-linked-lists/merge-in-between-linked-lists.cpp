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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int curr = 1;
        ListNode* ans = list1;
        ListNode* nxt = list1;
        while(curr<a){
            nxt = nxt->next;
            curr++;
        }
        ListNode* tmp = nxt->next;
        nxt->next = list2; 
        nxt = nxt->next;
        while(nxt->next){
            nxt = nxt->next;
        }

        while(curr<=b){
            tmp = tmp->next;
            curr++;
        }
        nxt->next = tmp;
        return ans;
    }
};