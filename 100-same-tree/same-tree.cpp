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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p && q || !q && p || p->val != q->val) return false;
        queue<TreeNode*> pQue;
        pQue.push(p);
        queue<TreeNode*> qQue;
        qQue.push(q);
        while(!pQue.empty() || !qQue.empty()){
            TreeNode* pFr = pQue.front();
            TreeNode* qFr = qQue.front();
            pQue.pop();
            qQue.pop();
            if(pFr->val != qFr-> val) return false;
            if(pFr->left){
                if(!qFr->left) return false;
                pQue.push(pFr->left);
            } 
                
            if(qFr->left){
                if(!qFr->left) return false;
                qQue.push(qFr->left);
            }

            if(pFr->right){
                if(!qFr->right) return false;
                pQue.push(pFr->right);
            }
            if(qFr->right){
                if(!pFr->right) return false;
                qQue.push(qFr->right);
            }
        }
        return pQue.empty() && qQue.empty();
    }
};