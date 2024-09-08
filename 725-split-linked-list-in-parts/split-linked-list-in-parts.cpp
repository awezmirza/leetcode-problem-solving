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

    int sizeOfLL(ListNode* head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = sizeOfLL(head);
        int nodesPerGroup = size / k;
        int extraNodes = size % k;
        vector<ListNode*> ans(k);

        ListNode* prev = new ListNode();
        prev->next = head;
        int j = 0;

        while (head) {
            ans[j] = head;
            j++;
            for (int i = 0; i < nodesPerGroup; i++) {
                if (head) {
                    prev = head;
                    head = head->next;
                } else {
                    break;
                }
            }
            if (extraNodes) {
                if (head) {
                    prev = head;
                    head = head->next;
                    extraNodes--;
                }
            }
            prev->next = NULL;
        }
        return ans;
    }
};