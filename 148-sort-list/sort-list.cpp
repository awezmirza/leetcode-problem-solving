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

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeSortedLL(ListNode* head1, ListNode* head2) {
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        ListNode* newHead = new ListNode();
        ListNode* iterator = newHead;

        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                iterator->next = temp1;
                temp1 = temp1->next;
            } else {
                iterator->next = temp2;
                temp2 = temp2->next;
            }
            iterator = iterator->next;
        }

        while (temp1) {
            iterator->next = temp1;
            iterator = iterator->next;
            temp1 = temp1->next;
        }

        while (temp2) {
            iterator->next = temp2;
            iterator = iterator->next;
            temp2 = temp2->next;
        }

        return newHead->next;
    }

    ListNode* sortLL(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* mid = findMid(head);

        ListNode* firstHead = head;
        ListNode* secondHead = mid->next;
        mid->next = NULL;

        ListNode* firstSortedHead = sortLL(firstHead);
        ListNode* secondSortedHead = sortLL(secondHead);

        return mergeSortedLL(firstSortedHead, secondSortedHead);        
    }

    ListNode* sortList(ListNode* head) {
        return sortLL(head);
    }
};