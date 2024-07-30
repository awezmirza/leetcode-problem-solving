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

    void dfs(TreeNode* root, int& ans) {
        if (!root) {
            return;
        }

        if (root->left && !root->left->left && !root->left->right) {
            ans += root->left->val;
        }

        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};