/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int val, int depth) {
        if (depth == 2) {
            TreeNode* left = root->left;
            TreeNode* newLeftNode = new TreeNode(val);
            root->left = newLeftNode;
            newLeftNode->left = left;

            TreeNode* right = root->right;
            TreeNode* newRightNode = new TreeNode(val);
            root->right = newRightNode;
            newRightNode->right = right;
            return;
        }
        if (root->left) {
            solve(root->left, val, depth - 1);
        }
        if (root->right) {
            solve(root->right, val, depth - 1);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        solve(root, val, depth);
        return root;
    }
};