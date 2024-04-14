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

    void solve(TreeNode* root, int& ans){
        
        if(root->left){
            if(!root->left->left && !root->left->right){
                ans += root->left->val;
            }
            solve(root->left, ans);
        }
        if(root->right)
            solve(root->right, ans);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int an = 0;
        solve(root, an);
        return an;
    }
};