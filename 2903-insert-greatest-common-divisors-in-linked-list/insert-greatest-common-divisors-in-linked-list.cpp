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
    int findGCD(int frst,int scnd){
        if(frst<scnd){
            return findGCD(scnd,frst);
        }
        if(frst % scnd == 0) return scnd;
        frst = frst % scnd;
        return findGCD(scnd,frst);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp->next){
            int frst = temp->val;
            int scnd = temp->next->val;
            int n = findGCD(frst,scnd);
            ListNode* curr = new ListNode(n,temp->next);
            temp->next = curr;
            temp = temp->next->next;
        }
        return head;
    }
};