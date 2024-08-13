/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* solve(Node* head) {

        Node* prev = NULL;
        while (head) {
            if (head->child) {
                Node* child = head->child;
                head->child = NULL;

                Node* childsFlatten = solve(child);
                Node* right = head->next;
                head->next = child;
                child->prev = head;

                childsFlatten->next = right;
                if (right) {
                    right->prev = childsFlatten;
                }
                
                head = right;
                prev = childsFlatten;
            } else {
                prev = head;
                head = head->next;
            }
        }
        return prev;
    }

    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};