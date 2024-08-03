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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* newHead = new ListNode();
        newHead->next = head;

        ListNode* iterator = newHead;

        while (iterator) {
            if (iterator->next && iterator->next->next && iterator->next->val == iterator->next->next->val) {
                int nextValOfIterator = iterator->next->val;
                ListNode* temp = iterator->next;
                if (nextValOfIterator == temp->next->val) {
                    while (temp && temp->val == nextValOfIterator) {
                        temp = temp->next;
                    }
                }
                iterator->next = temp;
            } else {
                iterator = iterator->next;
            }
        }

        return newHead->next;
    }
};