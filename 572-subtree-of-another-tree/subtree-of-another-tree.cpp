/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isTreeEqual(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!root1 || !root2 || root1->val != root2->val) {
            return false;
        }
        if(!isTreeEqual(root1->left, root2->left) || !isTreeEqual(root1->right, root2->right)) {
            return false;
        } 
        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* fr = q.front();
            q.pop();
            if (isTreeEqual(fr, subRoot)) {
                return true;
            }
            if (fr->left) {
                q.push(fr->left);
            }
            if(fr->right) {
                q.push(fr->right);
            }
        }
        return false;
    }
};