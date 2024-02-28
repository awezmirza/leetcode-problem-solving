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


    void solveUsingDFS(TreeNode* root, int depth, pair<int,int>& ansPair){
        if(!root->left){
            if(depth > ansPair.first){
                ansPair = {depth, root->val};
            }
        }
        if(!root->left && !root->right) return;
        if(root->left)
            solveUsingDFS(root->left, depth + 1, ansPair);
        if(root->right)
            solveUsingDFS(root->right, depth + 1, ansPair);
    }

    int findBottomLeftValue(TreeNode* root) {
        // Depth, LeftVal
        pair<int,int> ansPair = {0, root->val};
        solveUsingDFS(root, 0, ansPair);
        return ansPair.second;
    }
};