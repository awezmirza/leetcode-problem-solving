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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dmNode = new ListNode(0, head);
        unordered_map<int, ListNode*> mp;
        mp[0] = dmNode;
        int prefixSum = 0;
        while(head){
            prefixSum += head->val;
            if(mp.count(prefixSum)){
                ListNode* kahaParHai = mp[prefixSum];
                ListNode* deleteKarnaHai = kahaParHai;
                int toDltPfSumVal = prefixSum;
                while(deleteKarnaHai->next != head){
                    deleteKarnaHai = deleteKarnaHai->next;
                    toDltPfSumVal += deleteKarnaHai->val;
                    mp.erase(toDltPfSumVal);
                }
                kahaParHai->next = head->next;
            }
            else{
                mp[prefixSum] = head;
            }
            head = head->next;
        }
        return dmNode->next;
    }
};