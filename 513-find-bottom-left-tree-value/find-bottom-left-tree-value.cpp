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


    // void solveUsingDFS(TreeNode* root, int depth, pair<int,int>& ansPair){
    //     if(!root->left){
    //         if(depth > ansPair.first){
    //             ansPair = {depth, root->val};
    //         }
    //     }
    //     if(!root->left && !root->right) return;
    //     if(root->left)
    //         solveUsingDFS(root->left, depth + 1, ansPair);
    //     if(root->right)
    //         solveUsingDFS(root->right, depth + 1, ansPair);
    // }

    int solveUsingBFS(TreeNode* root){
        // Depth, Val
        pair<int,int> ans = {0,root->val};
        queue<pair<int,TreeNode*>> q;
        q.push({0, root});
        while(!q.empty()){
            auto front = q.front();
            TreeNode* fNode = front.second;
            int fDepth = front.first;
            q.pop();
            if(!fNode->left){
                if(fDepth>ans.first) ans = {fDepth, fNode->val};
            }
            else{
                q.push({fDepth+1, fNode->left});
            }
            if(fNode->right){
                q.push({fDepth+1, fNode->right});
            }
        }
        return ans.second;
    }

    int findBottomLeftValue(TreeNode* root) {
        int ans = solveUsingBFS(root);
        return ans;
    }
};