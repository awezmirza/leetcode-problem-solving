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

    TreeNode* dfs(TreeNode* root) {
        if (!root) {
            return root;
        }
        
        TreeNode* leftKaLeaf = NULL;
        TreeNode* right = root->right;
        if (root->left) {
            root->right = root->left;
            root->left = NULL;
            leftKaLeaf = dfs(root->right);
        }

        if (leftKaLeaf) {
            leftKaLeaf->right = right;
        }

        TreeNode* rightKaLeaf = NULL;
        if (right) {
            rightKaLeaf = dfs(root->right);
        }

        if (rightKaLeaf) {
            return rightKaLeaf;
        } else if (leftKaLeaf) {
            return leftKaLeaf;
        } 
        return root;
    }

    void flatten(TreeNode* root) {
        dfs(root);
    }
};