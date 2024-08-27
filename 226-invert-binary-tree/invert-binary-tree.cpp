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

    void dfs(TreeNode* root, TreeNode* ans) {
        
        ans->val = root->val;
        if (root->right) {
            ans->left = new TreeNode();
            dfs(root->right, ans->left);
        }
        if (root->left) {
            ans->right = new TreeNode();
            dfs(root->left, ans->right);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode* ans = new TreeNode();
        dfs(root, ans);
        return ans;
    }
};