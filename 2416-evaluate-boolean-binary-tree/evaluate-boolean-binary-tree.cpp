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

    bool dfs(TreeNode* root){
        if(!root->left){
            return root->val;
        }

        bool lft = dfs(root->left);
        bool rgt = dfs(root->right);

        if(root->val == 2){
                return lft | rgt;
        }
        return lft & rgt;
    }

    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};