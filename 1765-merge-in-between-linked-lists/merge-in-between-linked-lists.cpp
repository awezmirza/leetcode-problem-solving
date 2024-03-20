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
        ListNode* ans = list1;

        int ansIterator = 1;
        ListNode* currNodePointer = list1;
        while(ansIterator<a){
            currNodePointer = currNodePointer->next;
            ansIterator++;
        }

        ListNode* tmp = currNodePointer->next;

        currNodePointer->next = list2; 
        currNodePointer = currNodePointer->next;
        while(currNodePointer->next){
            currNodePointer = currNodePointer->next;
        }

        while(ansIterator<=b){
            ListNode* toDlt = tmp;
            tmp = tmp->next;
            delete(toDlt);
            ansIterator++;
        }
        
        currNodePointer->next = tmp;
        return ans;
    }
};