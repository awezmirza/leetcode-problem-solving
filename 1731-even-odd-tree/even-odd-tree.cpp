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
    bool isEvenOddTree(TreeNode* root) {
        // if(root->val % 2 == 0) return false;
        queue<TreeNode*> q;
        q.push(root);
        bool isEvenPass = 1;
        while(!q.empty()){
            int prevInserted = INT_MAX;
            if(isEvenPass) prevInserted = INT_MIN;
            int sz = q.size();
            while(sz--){
                TreeNode* fNode = q.front();
                q.pop();
                if(isEvenPass && (fNode->val%2 == 0 || fNode->val <= prevInserted)) return false;
                if(!isEvenPass && (fNode->val%2 != 0 || fNode->val >= prevInserted)) return false;
                prevInserted = fNode->val;
                if(fNode->left) q.push(fNode->left);
                if(fNode->right) q.push(fNode->right);
            }
            isEvenPass = !isEvenPass;
        }
        return true;
    }
};