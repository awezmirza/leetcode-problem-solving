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

    bool doDFSAndCheck(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p && q || !q && p || p->val != q->val) return false;
        bool forLeft = doDFSAndCheck(p->left,q->left);
        bool forRight = doDFSAndCheck(p->right,q->right);
        return forLeft && forRight;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = doDFSAndCheck(p,q);
        return ans;
    }
};